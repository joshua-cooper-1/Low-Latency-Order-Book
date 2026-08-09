#pragma once

#include <iostream>
#include <vector>


class Heap {
    protected:
        std::vector<int> heap;
        int length = 0;

    public:
        virtual bool is_heap_condition_satisfied(int parent, int child) = 0;
        virtual int choose_child(int leftChild, int rightChild) = 0;

        bool isEmpty();
        std::vector<int> getHeap();
        int peek_heap();

        void swap_places(int index_1, int index2);

        void heap_add(int element);

        void heap_remove();

        void print_heap();

};