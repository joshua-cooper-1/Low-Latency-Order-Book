#include "LinkedListHandler.h"

LinkedListHandler::~LinkedListHandler() {
    
    while (root != nullptr) {
        removeNodeFromTree(root);
    }
}


void LinkedListHandler::addNodeL1(LinkedListNodeL1* L1NodeToAdd, LinkedListNodeL1* current) {
    //binary search to find where to put in


    if (L1NodeToAdd == nullptr) {
        return;
    }

    if (root == nullptr) {
        root = L1NodeToAdd;
        root->setParent(nullptr);
        return;
    }
    
    if (current == nullptr) {
        current = root;
    }
    
    if (L1NodeToAdd->getPrice() == current->getPrice()) {
        return;

    }

    else if (L1NodeToAdd->getPrice() < current->getPrice()) {
        if (current->getLeftChildL1() != nullptr) {
            addNodeL1(L1NodeToAdd, current->getLeftChildL1());
            
        }
        else {
            current->setLeftChildL1(L1NodeToAdd);
            L1NodeToAdd->setParent(current);
            rebalanceAtNode(current);

        }
    }
    else if (L1NodeToAdd->getPrice() > current->getPrice()) {
        if (current->getRightChildL1() != nullptr) {
            addNodeL1(L1NodeToAdd, current->getRightChildL1());
            
        }
        else {
            current->setRightChildL1(L1NodeToAdd);
            L1NodeToAdd->setParent(current);
            rebalanceAtNode(current);
            return;

        }
    }

    
}
void LinkedListHandler::removeNodeL1(int price, LinkedListNodeL1* current) {

    if (root == nullptr) {
        return;
    }

    if (current == nullptr) {
        current = root;
        
    }

    if (price == current->getPrice()) {
        LinkedListNodeL1* rebalanceTarget = removeNodeFromTree(current);
        if (rebalanceTarget != nullptr) {
            rebalanceAtNode(rebalanceTarget);
        }
    } else if (price < current->getPrice()) {
        if (current->getLeftChildL1() != nullptr) {
            removeNodeL1(price, current->getLeftChildL1());
        }
    } else if (price > current->getPrice()) {
        if (current->getRightChildL1() != nullptr) {
            removeNodeL1(price, current->getRightChildL1());
        }
    }
}
LinkedListNodeL1* LinkedListHandler::removeNodeFromTree(LinkedListNodeL1* nodeL1ToRemove) {
    if (nodeL1ToRemove == nullptr) {
        return nullptr;
    }

    LinkedListNodeL1* parent = nodeL1ToRemove->getParent();
    LinkedListNodeL1* rebalanceNode = nullptr;

    //leaf node (0 children)
    if (nodeL1ToRemove->getLeftChildL1() == nullptr && nodeL1ToRemove->getRightChildL1() == nullptr) {
        if (parent != nullptr) {
            parent->removeChild(nodeL1ToRemove);
            rebalanceNode = parent;
        } else {
            this->root = nullptr;
            rebalanceNode = nullptr;
        }

        delete nodeL1ToRemove;
        return rebalanceNode;
    }

    //Single child (Left child only)
    if (nodeL1ToRemove->getLeftChildL1() != nullptr && nodeL1ToRemove->getRightChildL1() == nullptr) {
        LinkedListNodeL1* child = nodeL1ToRemove->getLeftChildL1();
        child->setParent(parent);

        if (parent != nullptr) {
            bool left = parent->removeChild(nodeL1ToRemove);
            if (left) {
                parent->setLeftChildL1(child);
            } else {
                parent->setRightChildL1(child);
            }
            rebalanceNode = parent;
        } else {
            this->root = child;
            rebalanceNode = child;
        }

        delete nodeL1ToRemove;
        return rebalanceNode;
    }

    //Single child (Right child only)
    if (nodeL1ToRemove->getLeftChildL1() == nullptr && nodeL1ToRemove->getRightChildL1() != nullptr) {
        LinkedListNodeL1* child = nodeL1ToRemove->getRightChildL1();
        child->setParent(parent);

        if (parent != nullptr) {
            bool left = parent->removeChild(nodeL1ToRemove);
            if (left) {
                parent->setLeftChildL1(child);
            } else {
                parent->setRightChildL1(child);
            }
            rebalanceNode = parent;
        } else {
            this->root = child;
            rebalanceNode = child;
        }

        delete nodeL1ToRemove;
        return rebalanceNode;
    }

    //two children
    LinkedListNodeL1* successor = nodeL1ToRemove->getInOrderSuccessor();
    LinkedListNodeL1* successorParent = successor->getParent();
    LinkedListNodeL1* successorRightChild = successor->getRightChildL1();

    
    if (successorParent != nodeL1ToRemove) {
        successorParent->setLeftChildL1(successorRightChild);
        if (successorRightChild != nullptr) {
            successorRightChild->setParent(successorParent);
        }

        successor->setRightChildL1(nodeL1ToRemove->getRightChildL1());
        if (nodeL1ToRemove->getRightChildL1() != nullptr) {
            nodeL1ToRemove->getRightChildL1()->setParent(successor);
        }

        rebalanceNode = successorParent;
    } else {
        
        rebalanceNode = successor;
    }

    
    successor->setLeftChildL1(nodeL1ToRemove->getLeftChildL1());
    if (nodeL1ToRemove->getLeftChildL1() != nullptr) {
        nodeL1ToRemove->getLeftChildL1()->setParent(successor);
    }

    
    successor->setParent(parent);
    if (parent == nullptr) {
        this->root = successor;
    } else {
        if (parent->getLeftChildL1() == nodeL1ToRemove) {
            parent->setLeftChildL1(successor);
        } else {
            parent->setRightChildL1(successor);
        }
    }

    delete nodeL1ToRemove;
    return rebalanceNode;
}

LinkedListNodeL1* LinkedListHandler::getNodeL1(int price, LinkedListNodeL1* current) {
                //binary search to find where to put in

    if (root == nullptr) {
        return nullptr;
    }

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
            //doesnt exist
            return nullptr;

        }

        
    }
    return nullptr;

    
}
void LinkedListHandler::addNodeL2(LinkedListNodeL2* NodeL2ToAdd) {
    if (NodeL2ToAdd == nullptr) {
        return;
    }
    int price = NodeL2ToAdd->getPrice();

    LinkedListNodeL1* nodeL1Pointer = getOrCreateNodeL1(price, root);
    nodeL1Pointer->addNodeL2(NodeL2ToAdd);
}

void LinkedListHandler::removeNodeL2(int orderId) {
    auto it = orderTracker.find(orderId);
    if (it != orderTracker.end()) {
        removeNodeL2(it->second);
    }
}

void LinkedListHandler::removeNodeL2(LinkedListNodeL2* nodeL2ToRemove) {
    if (nodeL2ToRemove == nullptr) return;

    int price = nodeL2ToRemove->getPrice();
    int orderId = nodeL2ToRemove -> getOrderId();
    LinkedListNodeL1* priceNode = getNodeL1(price, root);

    if (priceNode != nullptr) {
        priceNode->removeNodeL2(nodeL2ToRemove);

        if (!priceNode->hasOrders()) {
            removeNodeL1(price, nullptr);
        }
    }

    orderTracker.erase(orderId);
    delete nodeL2ToRemove;
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

    if (nodeL1 == nullptr) return 0;
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

    LinkedListNodeL1* oldRootParent = oldRoot->getParent();

    newRoot->setLeftChildL1(oldRoot);
    oldRoot->setRightChildL1(orphanSubtree);
    
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
    else if (oldRootParent-> getLeftChildL1() == oldRoot) {
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

    LinkedListNodeL1* oldRootParent = oldRoot->getParent();

    newRoot->setRightChildL1(oldRoot);
    oldRoot->setLeftChildL1(orphanSubtree);

    

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
    else if (oldRootParent->getRightChildL1() == oldRoot) {
        oldRootParent->setRightChildL1(newRoot);
    }

}

void LinkedListHandler::rebalanceTree(LinkedListNodeL1* node) {
    //rebalance to keep the search O(log N)

    if (node == nullptr) {
        return;
    }

    //check balance factor by doing height left child - height right child and if the modulus is greater than 1 then need to rebalance
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor >= -1 && balanceFactor <= 1) {
        return;
    }

    int balanceFactorLeft = 0;
    int balanceFactorRight = 0;

    if (node->getLeftChildL1() != nullptr) {
        balanceFactorLeft = getBalanceFactor(node->getLeftChildL1());
    }

    if (node->getRightChildL1() != nullptr) {
        balanceFactorRight = getBalanceFactor(node->getRightChildL1());
    }

    if (balanceFactor > 1 && balanceFactorLeft >= 0) {
        
        rotateRight(node);
    }
    else if (balanceFactor < -1 && balanceFactorRight <= 0) {
        
        rotateLeft(node);
    }
    else if (balanceFactor > 1 && balanceFactorLeft < 0) {
        rotateLeft(node->getLeftChildL1());
        rotateRight(node);
    }
    else if (balanceFactor < -1 && balanceFactorRight > 0) {
        rotateRight(node->getRightChildL1());
        rotateLeft(node);
    }



}



void LinkedListHandler::printTree() {
    if (root != nullptr) {
    root->printTree(); 
    std::cout << "\n";
    }
}

LinkedListNodeL1* LinkedListHandler::getOrCreateNodeL1(int price, LinkedListNodeL1* current) {
                //binary search to find where to put in

    

    if (root == nullptr) {
        LinkedListNodeL1* nodeL1 = new LinkedListNodeL1();
        nodeL1->setPrice(price);
        nodeL1->setParent(nullptr);
        root = nodeL1;
        return nodeL1;

    }

    if (current == nullptr) {
        current = root;
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

            rebalanceAtNode(current);
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
        

            rebalanceAtNode(current);
            return nodeL1;

        }
    }
    return nullptr;

    
}
 
void LinkedListHandler::rebalanceAtNode(LinkedListNodeL1* node) {
    while (node != nullptr) {
        rebalanceTree(node);
        node = node->getParent();
    }
}

void LinkedListHandler::addOrder(int price) {
    LinkedListNodeL1* nodeL1 = getOrCreateNodeL1(price, nullptr);
    LinkedListNodeL2* orderNodeL2 = (new LinkedListNodeL2());
    orderNodeL2->setPrice(price);
    orderNodeL2->setOrderId(orderId++);

    nodeL1->addNodeL2(orderNodeL2);


    orderTracker[orderNodeL2->getOrderId()] = orderNodeL2;

    


}

bool LinkedListHandler::isEmpty() {
    if (root == nullptr) {
      
        return true;
    }
    else {
        return false;
    }

}

LinkedListNodeL1* LinkedListHandler::getMinNode(LinkedListNodeL1* current) {

    if (current == nullptr) {
        return nullptr;
    }

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

    if (current == nullptr) {
        return nullptr;

    }

    if (current->getRightChildL1() == nullptr) {
        return current;
    }
    else {
        return getMaxNode(current->getRightChildL1());
    }
    
}

LinkedListNodeL1* LinkedListHandler::getNextBuy() {
    return getMaxNode(root);
}


void LinkedListHandler::buy(LinkedListNodeL2* buyOrder) {
    removeNodeL2(buyOrder);
}

void LinkedListHandler::sell(LinkedListNodeL2* sellOrder) {
    removeNodeL2(sellOrder);
}



