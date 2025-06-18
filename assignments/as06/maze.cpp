/*
  Rebecca Negrete
  rnegrete
  rnegrete0454@gmail.com
  maze.cpp
*/

#include "mazeFuncs.h"

// Public Funcs
maze::maze(int size) : size(size) {
  // set up for maze
  a = size * size;
  grid = new uint8_t [a];
  indexes = new int [a];
  make_maze = new disjointset(a);

  for (int i = 0; i < a; ++i) {
    grid[i] = 0xF;
    indexes[i] = i;
  }
}

maze::~maze() {
  delete[] grid;
  delete[] indexes;
  delete make_maze;
}

void maze::gen_maze() {
  grid[0] = 0xB;
  grid[a - 1] = 0xE;

  randomize_indexes();

  while(make_maze->get_num_sets() > 1) {
    for (int i = 0; i < a; ++i) {
      removeWalls(indexes[i]);
      if (indexes[i] == a) {
        randomize_indexes();
        i = 0;
      }
    }
  }
}

void maze::maze_to_str() {
  for (int i = 0; i < a; ++i) {
    if(((i + 1) % size) == 0) {
      std::cout << std::hex << (int)grid[i] << std::endl;
    }else{
      std::cout << std::hex << (int)grid[i];
    }
  }
}

// Private Funcs
void maze:: removeWalls(int i) {
  remove_wall(i, left(i), left_mask, right_mask);
  remove_wall(i, right(i), right_mask, left_mask);
  remove_wall(i, up(i), up_mask, down_mask);
  remove_wall(i, down(i), down_mask, up_mask);
}

void maze::remove_wall(int i, int j, int mask_I, int mask_J) {
  if (j > 0 && !make_maze->same_set(i, j)) {
    make_maze->unite(i,j);
    grid[i] &= mask_I;
    grid[j] &= mask_J;
  }
}


void maze::randomize_indexes() {
  int b, temp;
  int value = a - 1;

  for(int i = value; i > 0; --i) {
    b = rand() % (i + 1);
    temp = indexes[i];
    indexes[i] = indexes[b];
    indexes[b] = temp;
  }
}

int maze::left(int index) const {
  if (index % size == 0) {return -1;}
  return index - 1;
}

int maze::right(int index) const {
  if ((index + 1) % size == 0) {return -1;}
  return index + 1;
}

int maze::up(int index) const {
  if (index < size) {return -1;}
  return index - size;
}

int maze::down(int index) const {
  if (index >= (a - size)) {return -1;}
  return index + size;
}