#include <iostream>
#include <vector>
#include <cmath>

#include "LinkedListHandler.h"
#include "LinkedListNodeL1.h"
#include "LinkedListNodeL2.h"
//#include "LinkedListHandler.cpp"

class MatchingEngine {
    

    //LinkedListNodeL1* buys;
    //LinkedListNodeL1* sells;
    LinkedListHandler* buysHandler = new LinkedListHandler();
    LinkedListHandler* sellsHandler = new LinkedListHandler();


    public:
    
    MatchingEngine()  {}

  

    void addBuy(int price) {
        buysHandler->addOrder(price);
    }

    void addSell(int price) {
        sellsHandler->addOrder(price);
    }

    void showBuys() {
        buysHandler->printTree();
    }

    void showSells() {
        sellsHandler->printTree();
    }

    void matchTrades() {
        while (!buysHandler->isEmpty() && !sellsHandler->isEmpty()) {


            LinkedListNodeL2* buyOrder = buysHandler->getNextBuy()->getNextNodeL2();
            LinkedListNodeL2* sellOrder = sellsHandler->getNextSell()->getNextNodeL2();

            int buyPrice = buyOrder->getPrice();
            int sellPrice = sellOrder->getPrice();

            if (buyPrice >= sellPrice) {
                std::cout << "Selling 1 share at £" << sellPrice << ", bidding price: £" << buyPrice << ".";
                executeTrade(buyOrder, sellOrder);
                std:: cout << "\nSold!";
            }
            else {
                std::cout << "\nNo more sales available. Highest bid: £" << buyPrice << ", lowest sell: £" << sellPrice << ".";
                break;
            }
        }
    }

    void executeTrade(LinkedListNodeL2* buyOrder, LinkedListNodeL2* sellOrder) {
        buysHandler->buy(buyOrder);
        sellsHandler->sell(sellOrder);

    }

    void printTree() {
        buysHandler->printTree();
    }


};

int main() {
    MatchingEngine matchingEngine = MatchingEngine();

    matchingEngine.addBuy(5);
    matchingEngine.addBuy(6);
    matchingEngine.addBuy(4);
    matchingEngine.addBuy(12);

    matchingEngine.addSell(11);
    matchingEngine.addSell(13);

  
    std::cout << '\n';
    matchingEngine.printTree();
    matchingEngine.matchTrades();
    std::cout << '\n';
    
    std::cout << '\n';
    

  
};