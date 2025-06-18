/*
Rebecca Negrete
rnegrete
rnegrete0454@gmail.com
quicksortFuncs.cpp
Assignment 3 Quicksort
*/

#include "quicksort.h"

// A is the vector (quickSortVect)
// p is left index & r is right index of the vector

void VectorSort::sort(std::vector<int> &A) {
  int vectSize = A.size();
  quicksort(A, 0, (vectSize - 1));
}

void VectorSort::quicksort(std::vector<int> &A, int p, int r) {
  if (p < r) {
    auto q = lomutoParition(A, p, r);
    // don't "look ahead"
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
}

// helper function for partition
void VectorSort::swap(int &s, int &t) {
  int v = s;
  s = t;
  t = v;
}

int VectorSort::medianOfThree(std::vector<int> &A, int p, int r) {
  int leftVal = A[p];
  int rightVal = A[r];
  int middleVal = A[p + ((r - p) / 2)];

  // Find median value & swap into A[r] & return index of median val
  // Compare A[p], A[mid], and A[r]
  if ((leftVal <= middleVal && middleVal <= rightVal) || 
      (rightVal <= middleVal && middleVal <= leftVal)) {
        return (p + ((r - p) / 2));
  }else if ((leftVal <= middleVal && leftVal <= rightVal) ||
            (rightVal <= middleVal && leftVal <= middleVal)) {
    return p;
  }
  return r;
}

int VectorSort::lomutoParition(std::vector<int> &A, int p, int r) {
  // median of three use for paritioning
  if((r - p) > LomutoNum) {
    int median = medianOfThree(A, p, r);
    swap(A[median], A[r]);
  }

  //pivot
  auto x = A[r];

  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i + 1;
}
