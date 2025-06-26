/*
  File Name: linkedList.h
  Assignment: 21-1
*/

#include <iostream>
using namespace std;

class Node{
    public:
        string data;
        Node* next;
        Node* prev;
};

class List {
    public:
    List();
    ~List();

    class LinkedNode {
        public: 
            LinkedNode(string Value);

            // Sets our next and previous node
            void setNext(LinkedNode* Node); 
            void setPrev(LinkedNode* Node);

            // Returns our next and previous node
            LinkedNode* getNext();
            LinkedNode* getPrev();

            // returns value
            std::string getData();

        private:
            std::string data;
            LinkedNode* next;
            LinkedNode* prev;
    };

    // tail and head pointer
    LinkedNode* tail;  
    LinkedNode* head;  

    // insert front and back (last) input in the list
    void insertFront(string Newhead); 
    void insertBack(string Newtail);

    // remove tail and head of the list
    string removeHead();
    string removeTail(); 
    
};

