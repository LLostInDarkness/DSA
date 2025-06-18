/*
  Rebecca Negrete
  rnegrete
  rnegrete0454@gmail.com
  disjointSetFuncs.h
*/

#include <iostream>

class disjointset {
  public:
    disjointset(int size);   // constructor
    ~disjointset();  // destructor/destoryer
    void unite(int x, int y);
    int find(int x);
    int same_set(int x, int y);
    int get_num_sets();

  private:
    void link(int x, int y);
    int* p;  // parent
    int* r;  // rank
    const int SIZE;
    int sets;
};