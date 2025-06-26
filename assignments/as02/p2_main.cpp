/*
  p2_main.cpp
  Assignment 02: Integer Minimum Heap and Priority Queue
  Tested & Mostly Works
  - Haven't fully tested if it returns false if inputs are over heap bounds
  - Fully works after revisions 

  Purpose of the program is to input integer values to then be outputted
  into either a sorted array, removed if it's the lowest value, or printed
  as a heap.  Program should output false if the input amount exceeds 2.4
  million.
*/

#include "minHeap.h"
#include <iostream>

int main() {
   intMinHeap heap(2400000);

   for(int input; std::cin >> input;) {

      std::stringstream out;
 
      switch (input)
      {
      // Print the heap and the size of the heap on a single line of text
      case 0:
         std::cout << heap.toString() << " " << std::endl;
         break;
      // extract the minimum value from obj & print value on single line
      case (-1):
         std::cout << "extract min: " << heap.extractmin() << std::endl;
         break;
      // Call heapsort and print sorted array in descending order
      case (-2):{
         auto sortValues = heap.heapsort();

         std::cout << "sorted array: [";

         for(int i = 0; i < sortValues.second; i++) {
            std::cout << sortValues.first[i];
            if(i < sortValues.second - 1) {
               std::cout << ", ";
            }
         }
         std::cout << "]" << std::endl;
         delete[] sortValues.first;
         break;
      }
      // If inputs aren't 0, -1, or 2, insert to heap
      // And print on single line
      default:
         bool result = heap.heapinsert(input);
         if(result) {
            out << "insert: " << input;
            std::cout << out.str() << std::endl;
         }
         break;
      }
   }
}
