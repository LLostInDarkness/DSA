/*
  Rebecca Negrete
  rnegrete
  rnegrete0454@gmail.com
  mazeFuncs.h
*/

#include "disjointSetFuncs.h"
#include <algorithm>
#include <random>
#include <vector>


class maze {
  public:
    maze(int);
    ~maze();
    void gen_maze();
    void maze_to_str();

  private:
    void remove_wall(int i, int j, int mask_I, int mask_J);
    void removeWalls(int i);
    void randomize_indexes();
    int left(int) const;
    int right(int) const;
    int up(int) const;
    int down(int) const;
    uint8_t* grid;
    int* indexes;
    int a;
    int size;
    // directional masks/ints
    int left_mask = 11, right_mask = 14, up_mask = 7, down_mask = 13;
    // for making the maze
    disjointset* make_maze;
};