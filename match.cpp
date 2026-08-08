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


class MinHeap {
    std::vector<int> minHeap;
    int length = 0;

    public:

    std::vector<int> getMinHeap() {
        return minHeap;
    }


    void heap_add(int element) {
        int parentIndex;
        int holder;
        
        minHeap.push_back(element);
        length += 1;
        int height = std::log2(length);

        int pointer = length -1;

        for (int i = 0; i < height ; i ++) {

            parentIndex = (int) (pointer-1)/2;
            
            if (minHeap[parentIndex] > element) {
                holder = minHeap[parentIndex];
                minHeap[parentIndex] = minHeap[pointer];
                minHeap[pointer] = holder;
            }
            else {
                break;
            }

            pointer = parentIndex;
         
        }
        
        
    }

    void heap_remove() {
        int holder;


        minHeap[0] = minHeap[length-1];

        minHeap.pop_back();

        minHeap.shrink_to_fit();

        length -= 1;

        int height = std::log2(length);

        int pointer = 0;

        for (int i = 0 ; i < height ; i ++) {
            int leftChild = 2*pointer + 1;
            int rightChild = 2*pointer + 2;

            if (rightChild < length -1) {
                if (minHeap[rightChild] < minHeap[leftChild]) {
                    if (minHeap[rightChild] < minHeap[pointer]) {
                        holder = minHeap[rightChild];
                        minHeap[rightChild] = minHeap[pointer];
                        minHeap[pointer] = holder;

                        pointer = rightChild;
                    }
                    else {
                        break;
                    }   
                }
                else {
                    if (minHeap[leftChild] < minHeap[pointer]) {
                        holder = minHeap[leftChild];
                        minHeap[leftChild] = minHeap[pointer];
                        minHeap[pointer] = holder;

                        pointer = leftChild;
                    }
                    else {
                        break;
                    }

                }
            }
            else if (leftChild < length -1) {
                if (minHeap[leftChild] < minHeap[pointer]) {
                    holder = minHeap[leftChild];
                    minHeap[leftChild] = minHeap[pointer];
                    minHeap[pointer] = holder;
                }
                else {
                    break;
                }
            }
        }

    }

    void print_heap() {
        for (int i : minHeap) {
            std::cout << i << ' ';
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