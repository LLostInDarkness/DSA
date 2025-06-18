/*
Rebecca Negrete
rnegrete0454@gmail.com
minHeap.h
Assignment 02: Integer Minimum Heap and Priority Queue
Tested/Works
*/

#include <sstream>

// integer minimum heap with PQ 
class intMinHeap{
   public:
      intMinHeap(int cap);  // empty heap wth this capacity
      ~intMinHeap();  // clean up allocated memory  
      std::pair<int *, int> heapsort();  // return sorted array and size from heap
      std::string toString();  
      bool heapinsert(int); // add element to heap; return success
      // min functions should return 0 in empty heaps 
      int minimum();  // return value of A[root]
      int extractmin(); // return and remove A[root]
      void decreasekey(int i, int k);  // A[i] decreased to k
      bool isEmpty(){return size==0;}
      bool isFull();  
  private:
      int minOf3(int, int, int); // with bounds check!
      int left(int);
      int right(int);
      int parent(int);	
      void swap(int, int);
      void buildheap();  // convert array to a heap
      void heapify(int i);  // heapify at position i  
      int *A;  // array of integers - data
      int capacity; // size of array A
      int size; // data size in array
   };
