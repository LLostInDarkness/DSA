/*
  Rebecca Negrete
  rnegrete
  rnegrete0454@gmail.com
  p6_main.cpp
  Tested & Works

  PURPOSE:
    Generates a random maze string when given a number greater than 2. If given
    anything less, program will request the user to input a number higher
    than 2 and end the program.
*/

#include "mazeFuncs.h"

int main(int argc, char** argv) {
  srand(time(0));
  if (argc > 1) {
    int size = std::atoi(argv[1]);
    if (size < 3) {
      std::cerr << "Input a size greater than 2" << std::endl;
    }else{
      maze make_maze(size);
      make_maze.gen_maze();
      make_maze.maze_to_str();
    }
  }
}