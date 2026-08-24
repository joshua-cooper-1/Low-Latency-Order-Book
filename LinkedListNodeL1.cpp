#include "LinkedListNodeL1.h"
#include <iostream>
#include <algorithm>


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

void LinkedListNodeL1::addNodeL2(LinkedListNodeL2* NodeL2ToAdd) {
    
    if (headL2 == nullptr) {
        this->headL2 = NodeL2ToAdd;
        this->tailL2 = NodeL2ToAdd;
    }
    else {
        NodeL2ToAdd->setPrevNode(this->tailL2);
        this->tailL2->setNextNode(NodeL2ToAdd);
    }
    this->tailL2 = NodeL2ToAdd;
    
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

LinkedListNodeL1* LinkedListNodeL1::getParent() {
    return parent;
}

void LinkedListNodeL1::setParent(LinkedListNodeL1* parent) {
    this->parent = parent;
}

bool LinkedListNodeL1::removeChild(LinkedListNodeL1* child) {
    if (getLeftChildL1() == child) {
        setLeftChildL1(nullptr);
        return true;
    }
    else if (getRightChildL1() == child) {
        setRightChildL1(nullptr);
        return false;
    }

    return false;
}

LinkedListNodeL1* LinkedListNodeL1::getInOrderSuccessor() {
    LinkedListNodeL1* rightChild = getRightChildL1();

    return rightChild->getMinimum();
}

LinkedListNodeL1* LinkedListNodeL1::getMinimum() {
    if (getLeftChildL1() == nullptr) {
        return this;
    }
    else {
        return getLeftChildL1()->getMinimum();
    }
}

int LinkedListNodeL1::getHeight() {
    int maxHeight = 1;

    if (leftChildL1 != nullptr) {
        maxHeight = leftChildL1->getHeight() + 1;
    }
    if (rightChildL1 != nullptr) {
        maxHeight = std::max(maxHeight, rightChildL1->getHeight()+1);
    }

    return maxHeight;
}