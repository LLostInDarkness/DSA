/*
Rebecca Negrete
rnegrete
rnegrete0454@gmail.com
quicksortFuncs.cpp
Assignment 3 Quicksort
Tested/Works

Purpose: Recieves unspecified amount of input (will be integers) from STDIN.
Will return a sorted vector of all numerical inputs in ascending order.
*/

#include "quicksort.h"
#include <vector>
#include <iomanip>

int main() {
  std::vector<int> quickSortVect;

  // Gets inputs and sends them to the vector above before sorting
  for(int input; std::cin >> input;) {
    quickSortVect.push_back(input);
  }

  // Sorts the inputs given to STDIN
  VectorSort Start_Sort;
  Start_Sort.sort(quickSortVect);

  // Will output the inputs in ascending order, one input per line
  for(unsigned int i = 0; i < quickSortVect.size(); ++i) {
    std::cout << std::setw(9) << std::setfill('0') << quickSortVect[i]
    << std::endl;
  }
}
