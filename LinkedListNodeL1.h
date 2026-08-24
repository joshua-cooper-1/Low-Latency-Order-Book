#pragma once
#include "LinkedListNodeL2.h"


class LinkedListNodeL1 {
    private:
        
        int price;
        LinkedListNodeL2* headL2 = nullptr;
        LinkedListNodeL2* tailL2 = nullptr;

        LinkedListNodeL1* leftChildL1 = nullptr;
        LinkedListNodeL1* rightChildL1 = nullptr;
        LinkedListNodeL1* parent = nullptr;


    public:


        LinkedListNodeL2* getNextNodeL2();

        int getPrice();

        LinkedListNodeL1* getLeftChildL1();
        LinkedListNodeL1* getRightChildL1();

        void addNodeL2(LinkedListNodeL2* NodeL2);

        void setPrice(int price);

        void setLeftChildL1(LinkedListNodeL1* leftChildL1);

        void setRightChildL1(LinkedListNodeL1* rightChildL1);

        LinkedListNodeL1* getParent();

        void setParent(LinkedListNodeL1* parent);

        void printTree();

        bool removeChild(LinkedListNodeL1* child);

        LinkedListNodeL1* getInOrderSuccessor();

    

        LinkedListNodeL1* getMinimum();

        int getHeight();


};