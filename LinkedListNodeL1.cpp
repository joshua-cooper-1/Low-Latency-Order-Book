#include "LinkedListNodeL1.h"
#include <iostream>


LinkedListNodeL2* LinkedListNodeL1::getNextNodeL2() {
    return headL2;
}

int LinkedListNodeL1::getPrice() {
    return price;
}

LinkedListNodeL1* LinkedListNodeL1::getLeftChildL1() {
    return leftChildL1;
}

LinkedListNodeL1* LinkedListNodeL1::getRightChildL1() {
    return rightChildL1;
}

void LinkedListNodeL1::addNodeL2(LinkedListNodeL2* NodeL2) {
    
    if (headL2 == nullptr) {
        this->headL2 = NodeL2;
    }
    else {
        NodeL2->setPrevNode(this->tailL2);
        this->tailL2->setNextNode(NodeL2);
    }
    this->tailL2 = NodeL2;
    
}

void LinkedListNodeL1::setPrice(int price) {
    this->price = price;
}

void LinkedListNodeL1::setLeftChildL1(LinkedListNodeL1* leftChildL1) {
    this->leftChildL1 = leftChildL1;
}

void LinkedListNodeL1::setRightChildL1(LinkedListNodeL1* rightChildL1) {
    this->rightChildL1 = rightChildL1;
}

void LinkedListNodeL1::printTree() {
    
    if (getLeftChildL1() != nullptr) {
        getLeftChildL1()->printTree();
    }

    std::cout << this->price;
    if (getRightChildL1() != nullptr) {
        getRightChildL1()->printTree();
    }
}


