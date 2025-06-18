/*
  Name: Rebecca Negrete
  Pengo: rnegrete
  Email: rnegrete0454@gmail.com
  File Name: linkedListFuncs.cpp
  Assignment: 21-1
*/

#include <iostream>
#include "linkedList.h" 

using namespace std;

List::List() {
  head = nullptr;
  tail = nullptr;
}

// Sets up destructor for when the List::List() func ends
List::~List() {
  auto currentNode = head;
  while(currentNode) {
    auto nextNode = currentNode->getNext();
    delete currentNode;
    currentNode = nextNode;
  }
}

// Gets the value (line input) and assigns to data
List::LinkedNode::LinkedNode(string value) {
  data = value;
}

// Sets the next value as whatever the next node is assigned to
void List::LinkedNode::setNext(LinkedNode* Node) {
  next = Node;
}

// Sets the next value as whatever the previous node is assigned to
void List::LinkedNode::setPrev(LinkedNode* Node) {
  prev = Node;
}

// Gets next value of the list and returns it when called
List::LinkedNode* List::LinkedNode::getNext() {
  return next;
}

// Gets previous value of the list and returns it when called
List::LinkedNode* List::LinkedNode::getPrev() {
  return prev;
}

// Gets data from specified node
string List::LinkedNode::getData() {
  return data;
}

// Inserts value (data) at the front of the list
void List::insertFront(string Newhead) {
  LinkedNode* newHeadNode = new LinkedNode(Newhead);
  if(head == nullptr) {
      head = newHeadNode;
  }else{
      LinkedNode* getFront = head;
      while(getFront->getPrev()) {
          getFront = getFront->getPrev();
      }
  }
  
}

// Inserts value (data) at the end of the list
void List::insertBack(string Newtail) {
  LinkedNode* newTailNode = new LinkedNode(Newtail);
  if(tail == nullptr) {
      tail = newTailNode;
  }else{
      LinkedNode* getEnd = tail;
      while (getEnd->getNext() != nullptr) {
          getEnd = getEnd->getNext();

          getEnd->setNext(newTailNode);
      }
      
  }
}

// Removes head value w/ list::linkednode funcs & assigns with diff value
string List::removeHead() {
  auto tempVal = head->LinkedNode::getData();
  head = head->getNext();

  if(head == nullptr) {
      delete tail;     // Deletes tail (prev) value
      tail = nullptr;  // Sets tail to null
  }else{
      delete head->getPrev();
      head = nullptr;
      head->setPrev(nullptr);  // Head becomes null
  }
  return tempVal;  // tempVal is now the new value/data before head
}

// Removes tail value w/ list::linkednode funcs & assigns with diff value
string List::removeTail() {
  auto tempVal = tail->LinkedNode::getData();
  tail = tail->getNext();

  if(tail == nullptr) {
      delete head;
      head = nullptr;
  }else{
      delete tail->getNext();
      tail->setNext(nullptr);  // tail is a ssigned to nullptr
  }
  return tempVal;  // tempVal is now the new value/data after the tail
}

