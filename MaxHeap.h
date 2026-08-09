#pragma once

#include "Heap.h"

class MaxHeap : public Heap {
    public:
        bool is_heap_condition_satisfied(int parent, int child) override;
        int choose_child(int leftChild, int rightChild) override;
};