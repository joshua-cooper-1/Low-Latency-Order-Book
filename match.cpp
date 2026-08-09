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

class Heap {
    protected:
        std::vector<int> heap;
        int length = 0;
    public:

    virtual bool is_heap_condition_satisfied(int parent, int child) = 0;

    virtual int choose_child(int leftChild, int rightChild) = 0;

    std::vector<int> getMinHeap() {
        return heap;
    }

    int peek_heap() {
        return heap[0];
    }


    void heap_add(int element) {
        int parentIndex;
        int holder;
        
        heap.push_back(element);
        length += 1;
        int height = std::log2(length);

        int pointer = length -1;

        for (int i = 0; i < height ; i ++) {

            parentIndex = (int) (pointer-1)/2;
            
            if (!(is_heap_condition_satisfied(parentIndex, pointer))) {
          
                holder = heap[parentIndex];
                heap[parentIndex] = heap[pointer];
                heap[pointer] = holder;
            }
            else {
                break;
            }

            pointer = parentIndex;
         
        }
        
        
    }

    void heap_remove() {
        int holder;


        heap[0] = heap[length-1];

        heap.pop_back();

        heap.shrink_to_fit();

        length -= 1;

        int height = std::log2(length);

        int pointer = 0;

        for (int i = 0 ; i < height ; i ++) {
            int leftChild = 2*pointer + 1;
            int rightChild = 2*pointer + 2;

            if (rightChild < length -1) {
                if (choose_child(leftChild, rightChild) == rightChild) { //rightChild smaller than leftChild
                    if (!(is_heap_condition_satisfied(pointer, rightChild))) {
                        holder = heap[rightChild];
                        heap[rightChild] = heap[pointer];
                        heap[pointer] = holder;

                        pointer = rightChild;
                    }
                    else {
                        break;
                    }   
                }
                else {
                    if (!(is_heap_condition_satisfied(pointer, leftChild))) {
                        holder = heap[leftChild];
                        heap[leftChild] = heap[pointer];
                        heap[pointer] = holder;

                        pointer = leftChild;
                    }
                    else {
                        break;
                    }

                }
            }
            else if (leftChild < length -1) {
                if (!(is_heap_condition_satisfied(pointer, leftChild))) {
                    holder = heap[leftChild];
                    heap[leftChild] = heap[pointer];
                    heap[pointer] = holder;
                }
                else {
                    break;
                }
            }
        }

    }

    void print_heap() {
        for (int i : heap) {
            std::cout << i << ' ';
    }
    }

};


class MinHeap : public Heap {
    private:
        
        bool is_heap_condition_satisfied(int parent, int child) override {
            if (heap[parent] < heap[child]) {
                return true;
            }
            else {
                return false;
            }
        }

        int choose_child(int leftChild, int rightChild) override {
            if (heap[leftChild] < heap[rightChild]) {
                return leftChild;
            }
            else {
                return rightChild;
            }
        }
};


class MaxHeap : public Heap {
    private:
        
        bool is_heap_condition_satisfied(int parent, int child) override {
            if (heap[parent] > heap[child]) {
                return true;
            }
            else {
                return false;
            }
        }

        int choose_child(int leftChild, int rightChild) override {
            if (heap[leftChild] > heap[rightChild]) {
                return leftChild;
            }
            else {
                return rightChild;
            }
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