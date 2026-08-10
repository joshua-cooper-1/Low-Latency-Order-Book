#pragma once

class LinkedListNodeL2 {
    private:
        LinkedListNodeL2* prevNode;
        LinkedListNodeL2* nextNode;
        int price;
    
        int orderId;

    public:
        LinkedListNodeL2* getPrevNode();

        LinkedListNodeL2* getNextNode();

        int getPrice();

        int getOrderId();

        void setPrevNode(LinkedListNodeL2* prevNode);

        void setNextNode(LinkedListNodeL2* nextNode);

        void setPrice(int price);

        void setOrderId(int orderId);

};