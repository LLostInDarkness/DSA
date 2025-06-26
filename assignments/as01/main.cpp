/*
  File Name: linkedListFuncs.cpp
  Assignment: 21-1
*/

/*
    Purpose of this program is to input any amount of strings (either via
    a text file redirected to the program or input manually by the user).
    The output is the said input in reverse order using the stack function.
    The stack::Pop() function allows the output to be in reverse order.
    Working/Tested
    Program complies and works.  
    No errors and warnings after fully debugging.
*/

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main() {
    Stack reverse;
    string input;

    while(getline(cin, input)) {
        reverse.Push(input);
    }

    // If stack isn't empty print all data in reverse order
    // If stack is empty, end program with no output
    while(!reverse.isEmpty()) {
        cout << reverse.PrintStack() << endl;
        reverse.Pop();
    }
    return 0;
}
