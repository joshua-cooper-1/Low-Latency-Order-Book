#include "LinkedListNodeL1.h"
#include "LinkedListNodeL2.h"
#include <vector>
#include <unordered_map>
#include <iostream>

class LinkedListHandler {
    private:
        LinkedListNodeL1* root = nullptr;

        std::vector<int> idTracker;

        //need hashmap for orderId, addressOfNode. so can jump right to the node to remove an order.
        std::unordered_map<int, LinkedListNodeL2*> orderTracker;

        int orderId = 0;

    public:

        void addNodeL1(LinkedListNodeL1* L1NodeToAdd, LinkedListNodeL1* current = nullptr) {
            //binary search to find where to put in

            if (current == nullptr) {
                current = root;
            }
            

            if (root == nullptr) {
                
                root = L1NodeToAdd;
        
                return;
            }
            
           
            if (L1NodeToAdd->getPrice() == current->getPrice()) {
                return;

            }
            else if (L1NodeToAdd->getPrice() < current->getPrice()) {
                if (current->getLeftChildL1() != nullptr) {
                    return addNodeL1(L1NodeToAdd, current->getLeftChildL1());
                    
                }
                else {
                    current->setLeftChildL1(L1NodeToAdd);
                    return;

                }
            }
            else if (L1NodeToAdd->getPrice() > current->getPrice()) {
                if (current->getRightChildL1() != nullptr) {
                    return addNodeL1(L1NodeToAdd, current->getRightChildL1());
                    
                }
                else {
                    current->setRightChildL1(L1NodeToAdd);
                    return;

                }
            }
        
            
        }

        void removeNodeL1(int price) {
            //binary search to find the price to remove (probs not needed)
        }

        LinkedListNodeL1* getNodeL1(int price, LinkedListNodeL1* current) {
                        //binary search to find where to put in

            if (current == nullptr) {
                current = root;
            }
            

     
            
           
            if (price == current->getPrice()) {
                return current;

            }
            else if (price < current->getPrice()) {
                if (current->getLeftChildL1() != nullptr) {
                    return getNodeL1(price, current->getLeftChildL1());
                    
                }
                else {
                    //doesnt exist
                    return nullptr;

                }
            }
            else if (price > current->getPrice()) {
                if (current->getRightChildL1() != nullptr) {
                    return getNodeL1(price, current->getRightChildL1());
                    
                }
                else {
                    //diesbnt exist
                    return nullptr;

                }
            }
        
            
        }
        void addNodeL2(LinkedListNodeL2* NodeL2ToAdd) {
            //get the price somehow and then insert at the back of the queue?
            int price = NodeL2ToAdd->getPrice();

            LinkedListNodeL1* nodeL1Pointer = getNodeL1(price, root);

            if (nodeL1Pointer == nullptr) {
                LinkedListNodeL1 nodeL1;
                nodeL1.setPrice(price);
                nodeL1Pointer = &nodeL1;
                addNodeL1(nodeL1Pointer, nullptr);
            }

            nodeL1Pointer->addNodeL2(NodeL2ToAdd);


        }

        void removeNodeL2(int orderId) {
            //find index of where it is in L1 using separate tracker
            //find index of where it is in L2 using separate tracker
            //remove it
            LinkedListNodeL2* nodeL2 = orderTracker[orderId];

            LinkedListNodeL2* previousNodeL2 = nodeL2->getPrevNode();
            LinkedListNodeL2* nextNodeL2 = nodeL2->getNextNode();

            previousNodeL2->setNextNode(nextNodeL2);
            nextNodeL2->setPrevNode(previousNodeL2);

            //delete nodeL2?


        }



        LinkedListNodeL2* getNextOrder(int price) {
            LinkedListNodeL1* priceNodeL1 = getNodeL1(price, nullptr);

            if (priceNodeL1 == nullptr) {
                return nullptr;
            }

            LinkedListNodeL2* nextOrderNodeL2 = priceNodeL1->getNextNodeL2();

            return nextOrderNodeL2;

        }

        void rebalanceTree() {
            //rebalance to keep the search O(log N)
        }

        void printTree() {
     
            root->printTree(); 
        }
};

int main() {

    LinkedListHandler ls;

    LinkedListNodeL1 node;
    
    node.setPrice(3);
    ls.addNodeL1(&node);

    LinkedListNodeL1 node1;

    node1.setPrice(1);
    ls.addNodeL1(&node1);

    LinkedListNodeL1 node2;

    node2.setPrice(-1);
    ls.addNodeL1(&node2);

    LinkedListNodeL1 node3;

    node3.setPrice(2);
    ls.addNodeL1(&node3);

    ls.printTree();
    
}



