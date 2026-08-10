#include "LinkedListNodeL2.h"

LinkedListNodeL2* LinkedListNodeL2::getPrevNode() {
    return prevNode;
}

LinkedListNodeL2* LinkedListNodeL2::getNextNode() {
    return nextNode;
}

int LinkedListNodeL2::getPrice() {
    return price;
}

int LinkedListNodeL2::getOrderId() {
    return orderId;
}

void LinkedListNodeL2::setPrevNode(LinkedListNodeL2* prevNode) {
    this->prevNode = prevNode;
}

void LinkedListNodeL2::setNextNode(LinkedListNodeL2* nextNode) {
    this->nextNode = nextNode;
}

void LinkedListNodeL2::setPrice(int price) {
    this->price = price;
}

void LinkedListNodeL2::setOrderId(int orderId) {
    this->orderId = orderId;
}