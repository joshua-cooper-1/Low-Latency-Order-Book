
#include "MinHeap.h"



        
bool MinHeap::is_heap_condition_satisfied(int parent, int child) {
    if (heap[parent] < heap[child]) {
        return true;
    }
    else {
        return false;
    }
}

int MinHeap::choose_child(int leftChild, int rightChild) {
    if (heap[leftChild] < heap[rightChild]) {
        return leftChild;
    }
    else {
        return rightChild;
    }
}

