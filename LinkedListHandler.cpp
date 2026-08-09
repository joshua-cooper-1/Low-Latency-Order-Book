#include "LinkedListNodeL1.cpp"
#include "LinkedListNodeL2.cpp"

class LinkedListHandler {
    private:
        LinkedListNodeL1* root;

    public:

        void addNodeL1(LinkedListNodeL1* L1NodeToAdd) {
            //binary search to find where to put in
            
        }

        void removeNodeL1(int price) {
            //binary search to find the price to remove (probs not needed)
        }

        void addNodeL1(LinkedListNodeL2* L2NodeToAdd) {
            //get the price somehow and then insert at the back of the queue?
        }

        void removeNodeL2(LinkedListNodeL2* L2NodeToRemove) {
            //find index of where it is in L1 using separate tracker
            //find index of where it is in L2 using separate tracker
            //remove it
        }

        LinkedListNodeL1* getNextOrder(int price) {
            //get the order at the front of the queue for this price?
        }

        void rebalanceTree() {
            //rebalance to keep the search O(log N)
        }
}