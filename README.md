# Low-Latency Limit Order Book & Matching Engine (C++)

[![Language](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)](https://en.cppreference.com/w/cpp/17)

An in-memory **Limit Order Book (LOB)** and deterministic trade execution engine implemented in modern C++. 

The engine implements strict **Price-Time Priority (FIFO)** using a two-tier composite data structure: a self-balancing binary search tree (AVL tree) indexing active price levels and doubly-linked lists maintaining temporal queue ordering of resting limit orders.

---

## 🏛 Architecture & Data Structures

High-frequency and low-latency exchange order books require sub-microsecond bounds across three fundamental operations:
1. **Order Insertion:** Locate or allocate the corresponding limit price bucket and enqueue the order at the tail (O(log P)).
2. **Order Cancellation:** Lookup an active order by ID and unlink it in strictly O(1) time without scanning the book.
3. **Trade Execution:** Match resting bids and asks greedily from top-of-book (O(1)).

```
                            [ MatchingEngine ]
                              /            \
                       (Bids Book)      (Asks Book)
                   LinkedListHandler  LinkedListHandler
                             |                 |
                [AVL Tree of Price Levels (LinkedListNodeL1)]
                           /       \
                      £100.50     £101.00  <-- AVL Tree Nodes (Price Levels)
                         |            |
             [Doubly-Linked List of Orders (LinkedListNodeL2)]
                         |            |
                  +--------------+  +--------------+
                  | Order #1001  |  | Order #1003  |  (FIFO Head - Next to execute)
                  +--------------+  +--------------+
                         |                 |
                  +--------------+  +--------------+
                  | Order #1002  |  | Order #1004  |  (FIFO Tail - New arrivals)
                  +--------------+  +--------------+
```

### Component Breakdown
* **`LinkedListNodeL2` (Order Level):** Represents a single resting limit order. Encapsulates `orderId`, `price`, and forward/backward pointers (`prevNode`, `nextNode`).
* **`LinkedListNodeL1` (Price Level Bucket):** Represents an aggregated price bucket in the book. Contains head/tail pointers (`headL2`, `tailL2`) managing the temporal FIFO order queue, parent/child pointers for AVL balancing, and an RAII destructor cascading deallocations to resting orders.
* **`LinkedListHandler` (Order Book):** Manages book state, AVL rotations, and the price index. Integrates an O(1) index hash map (`std::unordered_map<int, LinkedListNodeL2*> orderTracker`) mapping unique order IDs directly to node memory addresses for instant unlinking.
* **`MatchingEngine`:** Coordinates independent bid and ask trees, resolving orders at top-of-book (`bestBid >= bestAsk`).

---

## ⚡ Algorithmic Complexity

| Operation | Standard Naive LOB | This Implementation | Theoretical Target | Notes |
| :--- | :---: | :---: | :---: | :--- |
| **Lookup Best Bid / Ask** | O(N) | **O(log P)** | O(1) | Traverses tree extremities; can be cached to O(1) |
| **Insert Limit Order** | O(N) | **O(log P)** | O(log P) | Binary search insertion + tail pointer append |
| **Cancel Order by ID** | O(N) | **O(1) amortised** | O(1) | Direct pointer lookup via hash map + O(1) DLL splice |
| **Top-of-Book Trade Match** | O(N) | **O(1)** | O(1) | Pops head of doubly-linked list at optimal price node |

*Legend: N = total resting orders across the entire book, P = total distinct active price levels.*

---

## 🛠️ Project Structure

```bash
.
├── CMakeLists.txt              # Build configuration
├── README.md                   # Project documentation
├── LinkedListHandler.h         # Order book interface & AVL tree controller
├── LinkedListHandler.cpp       # Tree balancing, node rotation, and order tracking
├── LinkedListNodeL1.h          # Price level bucket declaration
├── LinkedListNodeL1.cpp        # FIFO queue management & RAII destructor
├── LinkedListNodeL2.h          # Limit order entity declaration
├── LinkedListNodeL2.cpp        # Order getters and setters
└── matchLL.cpp                 # MatchingEngine coordination & simulation driver
```

---

## 🚀 Getting Started

### Prerequisites
* Clang++ (Apple Clang 12+) or GCC (g++ 9+)
* CMake 3.16+
* C++17 Standard Library support


### Direct Compilation
```bash
clang++ -std=c++17 -O3 -Wall -Wextra \
  LinkedListNodeL2.cpp \
  LinkedListNodeL1.cpp \
  LinkedListHandler.cpp \
  matchLL.cpp \
  -o matching_engine

./matching_engine
```

### Execution Output
```text
Buys:
4
5
6
12
Sells:
11
13
Selling 1 share at £11, bidding price: £12.
Sold!

No more sales available. Highest bid: £6, lowest sell: £13.
```

---

## ⚠️ Current Issues & Technical Debt

This project represents an active implementation of a low-latency matching engine. Key areas of ongoing optimisation and architectural improvements include:

### 1. Dynamic O(N) Height Calculation During Rebalancing
* **Current State:** `LinkedListNodeL1::getHeight()` recursively traverses left and right subtrees to compute node height on every query.
* **Bottleneck:** During AVL tree balancing (`rebalanceTree`), repeated recursive height calculations along the ancestor chain push worst-case insertion/deletion complexity toward O(P) rather than strict O(log P).
* **Remediation:** Store a cached `int height` directly in `LinkedListNodeL1` and update it locally in O(1) during left/right rotations.

### 2. Cache Locality & Heap Fragmentation
* **Current State:** Each individual order (`LinkedListNodeL2`) and price bucket (`LinkedListNodeL1`) is allocated dynamically on the heap via `new`.
* **Bottleneck:** Fragmented heap allocations cause CPU L1/L2 cache misses under high message throughput.
* **Remediation:** Implement a contiguous ring-buffer or custom fixed-size slab/arena memory allocator.

### 3. Unit-Share Execution & Volume Sweep
* **Current State:** Orders currently assume a uniform quantity of 1 unit per order node.
* **Bottleneck:** Does not model partial fills, execution of multi-lot orders, or aggressive orders sweeping multiple resting price tiers.
* **Remediation:** Extend `LinkedListNodeL2` with `quantity` and `cumQty` fields, enabling order-splitting logic during matching.

---

## 🗺️ Roadmap

- [x] Composite AVL tree + Doubly-linked list LOB architecture
- [x] O(1) direct order cancellation via hash map tracking
- [x] RAII price-bucket destructor to prevent memory leaks on queue cleanup
- [ ] Cached node heights for true O(log P) self-balancing rotations
- [ ] Order quantity, volume tracking, and multi-tier partial fill matching
- [ ] Automated unit test suite (GoogleTest / Catch2) for concurrent edge cases

---

