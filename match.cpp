#include <iostream>
#include <vector>
#include <cmath>

#include "MinHeap.h"
#include "MaxHeap.h"

//#include "LinkedListHandler.cpp"

class MatchingEngine {
    

    MaxHeap buys;
    MinHeap sells;


    public:
    
    MatchingEngine()  {}

  

    void addBuy(int buy) {
        buys.heap_add(buy);
    }

    void addSell(int sell) {
        sells.heap_add(sell);
    }

    void showBuys() {
        buys.print_heap();
    }

    void showSells() {
        sells.print_heap();
    }

    void matchTrades() {
        while (!buys.isEmpty() && !sells.isEmpty()) {
            if (buys.peek_heap() >= sells.peek_heap()) {
                
                std::cout << "Selling 1 share at £" << sells.peek_heap() << ", bidding price: £" << buys.peek_heap() << ".";
                executeTrade();
                std:: cout << "\nSold!";
            }
            else {
                std::cout << "\nNo more sales available. Highest bid: £" << buys.peek_heap() << ", lowest sell: £" << sells.peek_heap() << ".";
                break;
            }
        }
    }

    void executeTrade() {
        buys.heap_remove();
        sells.heap_remove();
    }


};

int main() {
    // MatchingEngine matchingEngine = MatchingEngine();

    // matchingEngine.addBuy(5);
    // matchingEngine.addBuy(6);
    // matchingEngine.addBuy(4);
    // matchingEngine.addBuy(12);

    // matchingEngine.addSell(11);
    // matchingEngine.addSell(13);

  
    // std::cout << '\n';

    // matchingEngine.matchTrades();
    // std::cout << '\n';
    
    // std::cout << '\n';
    

  
};