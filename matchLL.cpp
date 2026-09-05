#include <iostream>
#include <vector>
#include <cmath>

#include "LinkedListHandler.h"
#include "LinkedListNodeL1.h"
#include "LinkedListNodeL2.h"
//#include "LinkedListHandler.cpp"

class MatchingEngine {
    


    LinkedListHandler* buysHandler;
    LinkedListHandler* sellsHandler;


    public:
    
    MatchingEngine()  {
        buysHandler = new LinkedListHandler();
        sellsHandler = new LinkedListHandler();
    }

    ~MatchingEngine() {
        delete buysHandler;
        delete sellsHandler;
    }

  

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
            LinkedListNodeL1* bestBuyNode = buysHandler->getNextBuy();
            LinkedListNodeL1* bestSellNode = sellsHandler->getNextSell();

            if (bestBuyNode == nullptr || bestSellNode == nullptr) break;

            LinkedListNodeL2* buyOrder = bestBuyNode->getNextNodeL2();
            LinkedListNodeL2* sellOrder = bestSellNode->getNextNodeL2();

            if (buyOrder == nullptr || sellOrder == nullptr) break;

            int buyPrice = buyOrder->getPrice();
            int sellPrice = sellOrder->getPrice();

            if (buyPrice >= sellPrice) {
                std::cout << "Selling 1 share at £" << sellPrice << ", bidding price: £" << buyPrice << ".";
                executeTrade(buyOrder, sellOrder);
                std::cout << "\nSold!\n";
            } else {
                std::cout << "\nNo more sales available. Highest bid: £" << buyPrice << ", lowest sell: £" << sellPrice << ".\n";
                break;
            }
        }
    }

    void executeTrade(LinkedListNodeL2* buyOrder, LinkedListNodeL2* sellOrder) {
        buysHandler->buy(buyOrder);
        sellsHandler->sell(sellOrder);

    }

    void printTree() {
        std::cout << "Buys: ";
        buysHandler->printTree();
        std::cout << "Sells: ";
        sellsHandler->printTree();
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