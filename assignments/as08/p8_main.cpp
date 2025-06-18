/*
  Rebecca Negrete
  rnegrete
  rnegrete0454@gmail.com
  Assignment 8: BFS

  Tested & Works w/ no mem leaks

  Purpose:
  Allows user to input a maze using values 0-9 and a-f (including A-F).
  Checks to see if it's a valid maze (if not a input will give a std::cout 
  message).  If maze is vaild, program will run and output a lit of 
  coordinates descibing the path from (0,0) until the end at (x,y).
*/

#include <iostream>
#include <vector>
#include <queue>
#include <regex>
#include <string>
#include <stdexcept>

inline int left(int idx, int size) {
  if (idx % size == 0) {return -1;}
  return idx - 1;
}

inline int right(int idx, int size) {
  if ((idx + 1) % size == 0) {return -1;}
  return idx + 1;
}

inline int up(int idx, int size) {
  if(idx < size) {return -1;}
  return idx - size;
}

inline int down(int idx, int size, int a) {
  if (idx > (size - a)) {return -1;}
  return idx + a;
}

std::vector<int> BFS(const std::vector<int>& G, int start, int end, int len) {
  std::vector<int> parent(G.size(), -1);
  std::queue<int> Q;

  parent[start] = -2;
  Q.push(start);

  while(!Q.empty()) {
    int b = Q.front();
    Q.pop();

    for (int mask = 8; mask > 0; mask = mask >> 1) {
      if (!(mask & G[b])) {
        int travel;
        if (mask == 8) {
          travel = up(b, len);
        }else if (mask == 2) {
          travel = down(b, G.size(), len);
        }else if (mask == 4) {
          travel = left(b, len);
        }else{
          travel = right(b, len);
        }
      
        if (parent[travel] == -1) {
          Q.push(travel);
          parent[travel] = b;
        }
      }
    }
  }
  
  if (parent[end] == -1) {
    throw std::runtime_error("Path not found");
  }

  int idx = end;
  std::vector<int> path_;

  while (idx != -2) {
    path_.push_back(idx);
    idx = parent[idx];
  }
  std::reverse(path_.begin(), path_.end());

  return path_;

}

int char_to_hex(char h) {
  if ('A' <= h && h <= 'F') {
    return h - 'A' + 0xA;
  }else if ('a' <= h && h <= 'f') {
    return h - 'a' + 0xa;
  }else{
    return h - '0';
  }
}

int main() {
  std::vector<int> maze;

  unsigned int start = 0;
  unsigned int len = 0;
  std::string usr_input;

  std::regex hex_reg("[0-9A-Fa-f]+");
  while (std::getline(std::cin, usr_input)) {
    if (len == 0) {
      len = usr_input.size();
    }

    if(!std::regex_match(usr_input, hex_reg)) {
      std::cerr << "Invalid hex present" << std::endl;
    }

    if(usr_input.size() != len) {
      std::cerr << "Invalid maze" << std::endl;
    }

    for (char a : usr_input) {
      maze.push_back(char_to_hex(a));
    }
  }

  unsigned int end_ = maze.size() - 1;

  // Adds walls to start and end to avoid/don't need bounds check
  maze[start] |= 4;
  maze[end_] |= 1;

  std::vector<int> path_traveled;
  path_traveled = BFS(maze, start, end_, len);

  path_traveled[0] = 0;

  for (int i : path_traveled) {
    std::cout << '(' << (i % len) << ',' << (i / len) << ')' << std::endl;
  }
}