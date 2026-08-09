#include "LinkedListNodeL2.cpp"

class LinkedListNodeL1 {
    private:
        
        int price;
        LinkedListNodeL2* nextNodeL2;

        LinkedListNodeL1* leftChildL1;
        LinkedListNodeL1* rightChildL1;


    public:

        LinkedListNodeL1(LinkedListNodeL2* nextNodeL2, int price) {
            this->nextNodeL2 = nextNodeL2;
            this->price = price;
           
        }


        LinkedListNodeL2* getNextNodeL2() {
            return nextNodeL2;
        }

        int getPrice() {
            return price;
        }

        LinkedListNodeL1* getLeftChildL1() {
            return leftChildL1;
        }

        LinkedListNodeL1* getRightChildL1() {
            return rightChildL1;
        }

        void setNextNodeL2(LinkedListNodeL2* nextNodeL2) {
            this->nextNodeL2 = nextNodeL2;
        }

        void setPrice(int price) {
            this->price = price;
        }

        void setLeftChildL1(LinkedListNodeL1* leftChildL1) {
            this->leftChildL1 = leftChildL1;
        }

        void setRightChildL1(LinkedListNodeL1* rightChildL1) {
            this->rightChildL1 = rightChildL1;
        }


};