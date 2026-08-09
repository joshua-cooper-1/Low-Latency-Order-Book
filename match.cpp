#include <iostream>
#include <vector>
#include <cmath>

class MatchingEngine {
    

    std::vector<int> buys;
    std::vector<int> sells;


    public:
    
    MatchingEngine()  {}

    MatchingEngine(std::vector<int> buys, std::vector<int> sells)
        : buys(std::move(buys)), sells(std::move(sells)) {}

    void addBuy(int buy) {
        //logic for adding to a heap?
    }

    void addSell(int sell) {
        //logic for adding to a heap
    }


};

int main() {
    MinHeap minHeap = MinHeap();
    minHeap.heap_add(3);
    minHeap.heap_add(2);
    minHeap.heap_add(1);
    minHeap.heap_add(-1);
    minHeap.heap_add(6);
    minHeap.heap_add(7);
    

    minHeap.print_heap();

    std::cout << '\n';
    
    minHeap.heap_remove();

    minHeap.print_heap();
};