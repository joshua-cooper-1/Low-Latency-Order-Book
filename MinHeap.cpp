#include "Heap.cpp"

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
