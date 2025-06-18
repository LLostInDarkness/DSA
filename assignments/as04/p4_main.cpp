/*
Rebecca Negrete
rnegrete
rnegrete0454@gmail.com
p4_main.cpp
Assignment 3 Radix Bucket Sort
Tested/Works

Purpose: Recieve un specified amount of integers and sorts them in
ascending order.
*/

#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

void radixBucketSort(std::vector<int> &A, int n, int d, int k = 10) {
  // if input isn't empty, get the size of the input
  if (n != 0) {
    n = A.size();
  }
  // powerset like vector holding 10 buckets
  std::vector<std::vector<int>> bucket(k);

  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < n; ++j) {
      int r = (int)(A[j]/pow(10,i)) % 10;
      bucket[r].push_back(A[j]);
    }
    
    A.clear();
    // j is resetted back to 0 since the above for loop is finished
    for (int j = 0; j < k; ++j) {
      //append/add items from bucket[j] to A

      for (unsigned int m = 0; m < bucket[j].size(); ++m) {
        int bucketIndex = bucket[j][m];
        A.push_back(bucketIndex);
      }
      // Clears bucket
      bucket[j].clear();
    }
  }
}

int main() {
  constexpr int bucketNum = 9;
  std::vector<int> radixVect;
  int input;

  while (std::cin >> input) {
    radixVect.push_back(input);
  }

  radixBucketSort(radixVect, radixVect.size(), bucketNum, 10);
  
  for (unsigned int i = 0; i < radixVect.size(); i++) {
    std::cout << std::setw(bucketNum) << std::setfill('0')
    << radixVect[i] << std::endl;
  }
}