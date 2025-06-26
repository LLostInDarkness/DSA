/*
  quicksort.h
  Assignment 3 Quicksort
*/

#include <vector>
#include <iomanip>
#include <iostream>

class VectorSort{
  public:
    void sort(std::vector<int> &);
  private:
    int LomutoNum = 5;
    int medianOfThree(std::vector<int> &, int, int);
    void quicksort(std::vector<int> &, int, int);
    int lomutoParition(std::vector<int> &, int, int);
    void swap(int &, int &);
};
