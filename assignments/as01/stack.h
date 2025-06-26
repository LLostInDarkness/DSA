/*
  File Name: stack.h
  Assignment: 21-1
*/

#include <iostream>

using namespace std;

class Stack {
  private:
      struct item {
      string word;
      int stackValue;
      item* prevItem;
      };

  // Sets up stack pointer for future use
  // Is used to check if stack is empty
  item* stackPtr;

  public:
    void Push(string word);
    void Pop();
    int isEmpty();
    string PrintStack();

    // constructor when obj is created/set up obj
    Stack();
    // deconstructor when obj is destroyed (end program)
    ~Stack();
};
