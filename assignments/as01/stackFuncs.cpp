/*
  File Name: stackFuncs.cpp
  Assignment: 21-1
*/

#include <iostream>
#include "stack.h"

using namespace std;

// Makes sure the stack pointer goes to null
Stack::Stack() {
  stackPtr = nullptr;
}

// Destructor, runs when program ends
Stack::~Stack() {
  item* pointer1;
  item* pointer2;

  pointer1 = stackPtr;

  while(pointer1 != nullptr) {
    pointer2 = pointer1;
    pointer1 = pointer1->prevItem;
    pointer2->prevItem = nullptr;
    delete pointer2;
  }
}

// Push each line of data to the stack
void Stack::Push(string word) {
  item* newItemPtr = new item;

  newItemPtr->word = word;

  if(stackPtr == nullptr) {
      stackPtr = newItemPtr;
      stackPtr->prevItem = nullptr;
  }else{
      newItemPtr->prevItem = stackPtr;
      stackPtr = newItemPtr;
  }
}

// Pops/deletes most recent data value on top of stack
void Stack::Pop() {
  if(stackPtr != nullptr)  {
      item* p = stackPtr;
      stackPtr = stackPtr->prevItem;
      p->prevItem = nullptr;
      delete p;  // deletes top of stack
  }
}

// Prints stack's contents
string Stack::PrintStack() {
  
  item* p = stackPtr;
  return p->word;
}

int Stack::isEmpty() {
  if(stackPtr == nullptr) {
      return 1;
  }else{
      return 0;
  }
}

