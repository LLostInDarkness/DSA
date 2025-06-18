/*
Rebecca Negrete
rnegrete0454@gmail.com
minHeapFuncs.cpp
Assignment 02: Integer Minimum Heap and Priority Queue

Tested & Works (Resubmission)
- Fixed memory leak and other problems
*/

#include "minHeap.h"

// Starts with empty heap
intMinHeap::intMinHeap(int cap) {
   capacity = cap;
   A = new int[capacity];
   size = 0;
}

// For end of program, cleans up allocated mem
intMinHeap::~intMinHeap() {
   delete[] A;
   size = 0;
   capacity = 0;
}

std::pair<int *, int> intMinHeap::heapsort() {
   // If empty, make a pair that contains size & nullptr
   if(isEmpty()) {
      std::make_pair(nullptr, size);
   }

  // Using a temp variable to sort the values
   int *tempVar = A;
   A = new int[size];
   std::copy(tempVar, tempVar + size, A);
   int tempSize = size;

   for(int i = size - 1; i > 0; i--) {
      swap(0, i);
      size--;
      heapify(0);
   }

   int *sortedValues = A;
   size = tempSize;
   A = tempVar;

   return std::make_pair(sortedValues, size);
}

// Returns heap size & what's in the heap
std::string intMinHeap::toString() {
   std::stringstream output;
   output << "heap " << size << ": ";

   for(int i = 0; i < size; i++) {
      output << A[i];
      
      if(i < size - 1) {
         output << ", ";
      }
   }
   return output.str();
}

// Return true if input can beinserted into the heap
// Return false if the heap is full
bool intMinHeap::heapinsert(int value) {
   // if full, don't insert, instead return false
   if(isFull()) {return false;}

   // If not full, then do the following
   A[size] = value + 1;
   size++;
   decreasekey(size - 1, value);

   //After return true
   return true;
}

// Gets/returns min value at the root
int intMinHeap::minimum() {
   if(isEmpty()) {return 0;}

   // If not empty, return first elm/root
   return A[0];
}

// Return value of A[root] and removes it from heap
int intMinHeap::extractmin() {
   if(isEmpty()) {return 0;}

   int min = A[0];
   A[0] = A[size-1];
   size--;

   heapify(0);

   return min;
}

// A[i] decreased to k
void intMinHeap::decreasekey(int i, int k) {
   if(i < 0 ||i >= size || A[i] < k) {return;}
   A[i] = k;

   while (i > 0 && A[parent(i)] > A[i]){
      swap(i, parent(i));
      i = parent(i);
   }
}

// If size is capacity, return true, if not return false
bool intMinHeap::isFull() {return size == capacity;}

// PRIVATE ATTRIBUTES
// Bounds Check w/ j (left) & k (right)
int intMinHeap::minOf3(int i, int j, int k) {
   int minVal = i;
   
   if(j < size && A[minVal] > A[j]) {minVal = j;}
   
   if(k < size && A[minVal] > A[k]) {minVal = k;}

   return minVal;
}

// Left Value
int intMinHeap::left(int i) {return (2 * i + 1);}

// Right Value
int intMinHeap::right(int i) {return (2 * i + 2);}

// Parent Value of Both Left & Right
int intMinHeap::parent(int i) {return ((i - 1) / 2);}

// Swapping one index to the other
void intMinHeap::swap(int s, int t) {
   int v = A[s];
   A[s] = A[t];
   A[t] = v;
}

// Convert array to a heap
void intMinHeap::buildheap() {
   for(int i = size/2 - 1; i >= 0; i--) {heapify(i);}
}

// Heapify at position i
void intMinHeap::heapify(int i) {
   int n = minOf3(i, left(i), right(i));
   if(n != i) {
      swap(i, n);
      heapify(n);
   }
}
