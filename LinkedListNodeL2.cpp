class LinkedListNodeL2 {
    private:
        LinkedListNodeL2* nextNode;
        int price;
        int user_id;

    public:

        LinkedListNodeL2(LinkedListNodeL2* nextNode, int price, int user_id) {
            this->nextNode = nextNode;
            this->price = price;
            this->user_id = user_id;
        }


        LinkedListNodeL2* getNextNode() {
            return nextNode;
        }

        int getPrice() {
            return price;
        }

        int getUserId() {
            return user_id;
        }

        void setNextNode(LinkedListNodeL2* nextNode) {
            this->nextNode = nextNode;
        }

        void setPrice(int price) {
            this->price = price;
        }

        void setUserId(int userId) {
            this->user_id = user_id;
        }



        
    

};