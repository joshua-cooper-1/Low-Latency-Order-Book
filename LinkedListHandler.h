#pragma once
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

        void addNodeL1(LinkedListNodeL1* L1NodeToAdd, LinkedListNodeL1* current);

        void removeNodeL1(int price, LinkedListNodeL1* current);

        void removeNodeFromTree(LinkedListNodeL1* nodeL1ToRemove);

        LinkedListNodeL1* getNodeL1(int price, LinkedListNodeL1* current);


        void addNodeL2(LinkedListNodeL2* NodeL2ToAdd);

        void removeNodeL2(int orderId);
        void removeNodeL2(LinkedListNodeL2* nodeL2ToRemove);



        LinkedListNodeL2* getNextOrder(int price);

        int getBalanceFactor(LinkedListNodeL1* nodeL1);

        void rotateLeft(LinkedListNodeL1* rootToStartFrom);

        void rotateRight(LinkedListNodeL1* rootToStartFrom) {}

        void rebalanceTree();

        void printTree();
        

        LinkedListNodeL1* getOrCreateNodeL1(int price, LinkedListNodeL1* current);

        void addOrder(int price);

        bool isEmpty();

        LinkedListNodeL1* getMinNode(LinkedListNodeL1* current);

        LinkedListNodeL1* getNextSell();
        LinkedListNodeL1* getMaxNode(LinkedListNodeL1* current);
        
        LinkedListNodeL1* getNextBuy();

        void buy(LinkedListNodeL2* buyOrder);
        void sell(LinkedListNodeL2* sellOrder);


    };
//need function to remove something if order executed