/*
  Rebecca Negrete
  rnegrete
  rnegrete0454@gmail.com
  disjointSet.cpp
*/

#include "disjointSetFuncs.h"

// Public Functions
disjointset::disjointset(int size) : SIZE(size){
  p = new int[size];
  r = new int[size];

  sets = size;

  for(int i = 0; i < SIZE; ++i) {
    p[i] = i;
    r[i] = 0;
  }
}

disjointset::~disjointset() {
  delete[] p;
  delete[] r;
}

void disjointset::unite(int x, int y) {
  if (x == y || 0 > x || SIZE <= x || 0 > y || SIZE <= y) {return;}

  link(find(x),find(y));
  sets--;
}

int disjointset::find(int x) {
  if (0 > x || SIZE <= x) {return -1;}
  if (p[x] == x) {
    return x;
  }
  p[x] = find(p[x]);
  return p[x];
}

int disjointset::same_set(int x, int y) {
  if (x == y || 0 > x || SIZE <= x || 0 > y || SIZE <= y) {return false;}
  return find(x) == find(y);
}

int disjointset::get_num_sets() {
  return sets;
}

// Private Functions
void disjointset::link(int x, int y) {
  if(x == y) {return;}
  if(r[x] > r[y]) {
    p[y] = x;
  }else{
    p[x] = y;
    if(r[x] == r[y]) {
      r[y]++;
    }
  }
}