#include "LinkedListHandler.h"




void LinkedListHandler::addNodeL1(LinkedListNodeL1* L1NodeToAdd, LinkedListNodeL1* current = nullptr) {
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

void LinkedListHandler::removeNodeL1(int price, LinkedListNodeL1* current) {
                   //binary search to find where to put in

    if (current == nullptr) {
        current = root;
    }
    
    if (price == current->getPrice()) {
        removeNodeFromTree(current);

    }
    else if (price < current->getPrice()) {
        if (current->getLeftChildL1() != nullptr) {
                removeNodeL1(price, current->getLeftChildL1());
            
        }
        else {
            //doesnt exist
            return;

        }
    }
    else if (price > current->getPrice()) {
        if (current->getRightChildL1() != nullptr) {
            removeNodeL1(price, current->getRightChildL1());
            
        }
        else {
            //diesbnt exist
            return;

        }

        
    }
    return;

    

}

void LinkedListHandler::removeNodeFromTree(LinkedListNodeL1* nodeL1ToRemove) {
    if (nodeL1ToRemove->getLeftChildL1() == nullptr && nodeL1ToRemove->getRightChildL1() == nullptr) {
        if (nodeL1ToRemove->getParent() != nullptr) {
            LinkedListNodeL1* parent = nodeL1ToRemove->getParent();
            parent->removeChild(nodeL1ToRemove);
        }
    }
    else if (nodeL1ToRemove-> getLeftChildL1() != nullptr && nodeL1ToRemove->getRightChildL1() == nullptr) {
        if (nodeL1ToRemove->getParent() != nullptr) {
            LinkedListNodeL1* parent = nodeL1ToRemove->getParent();
            bool left = parent->removeChild(nodeL1ToRemove);

            LinkedListNodeL1* grandChild = nodeL1ToRemove->getLeftChildL1();

            if (left) {
                parent->setLeftChildL1(grandChild);
                grandChild->setParent(parent);
            }
            else {
                parent->setRightChildL1(grandChild);
                grandChild->setParent(parent);
            }
        }
    }
    else if (nodeL1ToRemove-> getLeftChildL1() == nullptr && nodeL1ToRemove->getRightChildL1() != nullptr) {
        if (nodeL1ToRemove->getParent() != nullptr) {
            LinkedListNodeL1* parent = nodeL1ToRemove->getParent();
            bool left = parent->removeChild(nodeL1ToRemove);

            LinkedListNodeL1* grandChild = nodeL1ToRemove->getRightChildL1();

            if (left) {
                parent->setLeftChildL1(grandChild);
                grandChild->setParent(parent);
            }
            else {
                parent->setRightChildL1(grandChild);
                grandChild->setParent(parent);
            }
        }
    }
    else {//has two children
        LinkedListNodeL1* newNode = nodeL1ToRemove->getInOrderSuccessor();

        if (nodeL1ToRemove->getParent() != nullptr) {
            LinkedListNodeL1* parent = nodeL1ToRemove->getParent();
            bool left = parent->removeChild(nodeL1ToRemove);

            

            if (left) {
                parent->setLeftChildL1(newNode);
                newNode->setParent(parent);
            }
            else {
                parent->setRightChildL1(newNode);
                newNode->setParent(parent);
            }
        }

    }
}

LinkedListNodeL1* LinkedListHandler::getNodeL1(int price, LinkedListNodeL1* current) {
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
    return nullptr;

    
}
void LinkedListHandler::addNodeL2(LinkedListNodeL2* NodeL2ToAdd) {
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

void LinkedListHandler::removeNodeL2(int orderId) {
    //find index of where it is in L1 using separate tracker
    //find index of where it is in L2 using separate tracker
    //remove it
    LinkedListNodeL2* nodeL2ToRemove = orderTracker[orderId];

    LinkedListNodeL2* previousNodeL2 = nodeL2ToRemove->getPrevNode();
    LinkedListNodeL2* nextNodeL2 = nodeL2ToRemove->getNextNode();

    if (previousNodeL2 != nullptr) {
    previousNodeL2->setNextNode(nextNodeL2);
    }
    if (nextNodeL2 != nullptr) {
    nextNodeL2->setPrevNode(previousNodeL2);
    }

    //delete nodeL2?


}

void LinkedListHandler::removeNodeL2(LinkedListNodeL2* nodeL2ToRemove) {
    //find index of where it is in L1 using separate tracker
    //find index of where it is in L2 using separate tracker
    //remove it


    LinkedListNodeL2* previousNodeL2 = nodeL2ToRemove->getPrevNode();

    LinkedListNodeL2* nextNodeL2 = nodeL2ToRemove->getNextNode();


    if (previousNodeL2 != nullptr) {
    previousNodeL2->setNextNode(nextNodeL2);
    }
    if (nextNodeL2 != nullptr) {
    nextNodeL2->setPrevNode(previousNodeL2);
    }
    //delete nodeL2?


}



LinkedListNodeL2* LinkedListHandler::getNextOrder(int price) {
    LinkedListNodeL1* priceNodeL1 = getNodeL1(price, nullptr);

    if (priceNodeL1 == nullptr) {
        return nullptr;
    }

    LinkedListNodeL2* nextOrderNodeL2 = priceNodeL1->getNextNodeL2();

    return nextOrderNodeL2;

}

int LinkedListHandler::getBalanceFactor(LinkedListNodeL1* nodeL1) {
    int heightLeftChild;
    int heightRightChild;

    if (nodeL1->getLeftChildL1() != nullptr) {
        heightLeftChild = nodeL1->getLeftChildL1()->getHeight();
    }
    else {
        heightLeftChild = 0;
    }

    if (nodeL1->getRightChildL1() != nullptr) {
        heightRightChild = nodeL1->getRightChildL1()->getHeight();
    }
    else {
        heightRightChild = 0;
    }

    int balanceFactor = heightLeftChild - heightRightChild;

    return balanceFactor;
}

void LinkedListHandler::rotateLeft(LinkedListNodeL1* rootToStartFrom) {
    if (rootToStartFrom == nullptr || rootToStartFrom->getRightChildL1() == nullptr) {
        return;
    }

    LinkedListNodeL1* oldRoot = rootToStartFrom;

    LinkedListNodeL1* newRoot = oldRoot->getRightChildL1();

    LinkedListNodeL1* orphanSubtree = newRoot->getLeftChildL1();

    newRoot->setLeftChildL1(oldRoot);
    oldRoot->setRightChildL1(orphanSubtree);

    LinkedListNodeL1* oldRootParent = oldRoot->getParent();

    oldRoot->setParent(newRoot);
    newRoot->setParent(oldRootParent);

    if (orphanSubtree != nullptr) {
        orphanSubtree->setParent(oldRoot);
    }

    if (oldRootParent == nullptr) {
        this->root = newRoot;
    }
    else if (oldRootParent->getRightChildL1() == oldRoot) {
        oldRootParent->setRightChildL1(newRoot);
    }
    else {
        oldRootParent->setLeftChildL1(newRoot);
    }
}

void LinkedListHandler::rotateRight(LinkedListNodeL1* rootToStartFrom) {

    if (rootToStartFrom == nullptr || rootToStartFrom->getLeftChildL1() == nullptr) {
        return;
    }

    LinkedListNodeL1* oldRoot = rootToStartFrom;

    LinkedListNodeL1* newRoot = oldRoot->getLeftChildL1();

    LinkedListNodeL1* orphanSubtree = newRoot->getRightChildL1();

    newRoot->setRightChildL1(oldRoot);
    oldRoot->setLeftChildL1(orphanSubtree);

    LinkedListNodeL1* oldRootParent = oldRoot->getParent();

    oldRoot->setParent(newRoot);
    newRoot->setParent(oldRootParent);

    if (orphanSubtree != nullptr) {
        orphanSubtree->setParent(oldRoot);
    }

    if (oldRootParent == nullptr) {
        this->root = newRoot;
    }
    else if (oldRootParent->getLeftChildL1() == oldRoot) {
        oldRootParent->setLeftChildL1(newRoot);
    }
    else {
        oldRootParent->setRightChildL1(newRoot);
    }

}

void LinkedListHandler::rebalanceTree() {
    //rebalance to keep the search O(log N)

    //check balance factor by doing height left child - height right child and if the modulus is greater than 1 then need to rebalance
    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor == 0) {
        return;
    }

    int balanceFactorLeft = 0;
    int balanceFactorRight = 0;

    if (root->getLeftChildL1() != nullptr) {
        balanceFactorLeft = getBalanceFactor(root->getLeftChildL1());
    }

    if (root->getRightChildL1() != nullptr) {
        balanceFactorRight = getBalanceFactor(root->getRightChildL1());
    }

    if (balanceFactor > 1 && balanceFactorLeft >= 0) {
        //root.rightRotate()
    }
    else if (balanceFactor < -1 && balanceFactorRight <= 0) {
        //root.leftRotate()
    }
    else if (balanceFactor > 1 && balanceFactorLeft < 0) {
        //root.leftChild.leftRotate()
        //root.rightRotate()
    }
    else if (balanceFactor < -1 && balanceFactorRight > 0) {
        //root.rightChild.rightRotate()
        //root.leftRotate()
    }



}



void LinkedListHandler::printTree() {

    root->printTree(); 
}

LinkedListNodeL1* LinkedListHandler::getOrCreateNodeL1(int price, LinkedListNodeL1* current) {
                //binary search to find where to put in

    if (current == nullptr) {
        current = root;
    }
    

    if (root == nullptr) {
        LinkedListNodeL1* nodeL1 = new LinkedListNodeL1();
        nodeL1->setPrice(price);
        root = nodeL1;
        return nodeL1;

    }
    
    
    if (price == current->getPrice()) {
        return current;

    }
    else if (price < current->getPrice()) {
        if (current->getLeftChildL1() != nullptr) {
            return getOrCreateNodeL1(price, current->getLeftChildL1());
            
        }
        else {
            //create new
            LinkedListNodeL1* nodeL1 = new LinkedListNodeL1();
            nodeL1->setPrice(price);

            current->setLeftChildL1(nodeL1);
            nodeL1->setParent(current);
            return nodeL1;

        }
    }
    else if (price > current->getPrice()) {
        if (current->getRightChildL1() != nullptr) {
            return getOrCreateNodeL1(price, current->getRightChildL1());
            
        }
        else {
            //create new

            LinkedListNodeL1* nodeL1 = new LinkedListNodeL1();
            nodeL1->setPrice(price);

            current->setRightChildL1(nodeL1);
            nodeL1->setParent(current);
            std::cout << price;
            return nodeL1;

        }
    }
    return nullptr;

    
}

void LinkedListHandler::addOrder(int price) {
    LinkedListNodeL1* NodeL1 = getOrCreateNodeL1(price, nullptr);
    LinkedListNodeL2* orderNodeL2 = (new LinkedListNodeL2());
    orderNodeL2->setPrice(price);
    orderNodeL2->setOrderId(orderId++);

    NodeL1->addNodeL2(orderNodeL2);
    if (root == nullptr) {
        root = NodeL1;
    }


}

bool LinkedListHandler::isEmpty() {
    if (root == nullptr) {
        std::cout << "HI";
        return true;
    }
    else {
        return false;
    }

}

LinkedListNodeL1* LinkedListHandler::getMinNode(LinkedListNodeL1* current) {


    if (current->getLeftChildL1() == nullptr) {
        return current;
    }
    else {
        return getMinNode(current->getLeftChildL1());
    }
}

LinkedListNodeL1* LinkedListHandler::getNextSell() {
    return getMinNode(root);
}

LinkedListNodeL1* LinkedListHandler::getMaxNode(LinkedListNodeL1* current) {
    if (current->getRightChildL1() == nullptr) {
        return current;
    }
    else {
        return getMaxNode(current->getRightChildL1());
    }
    return nullptr;
}

LinkedListNodeL1* LinkedListHandler::getNextBuy() {
    return getMaxNode(root);
}


void LinkedListHandler::buy(LinkedListNodeL2* buyOrder) {

    if (buyOrder->getNextNode() == nullptr) {

        
        removeNodeL1(buyOrder->getPrice(), nullptr);
    }
    removeNodeL2(buyOrder);

}

void LinkedListHandler::sell(LinkedListNodeL2* sellOrder) {
    if (sellOrder->getNextNode() == nullptr) {
        
        removeNodeL1(sellOrder->getPrice(), nullptr);
    }
    removeNodeL2(sellOrder);
}


