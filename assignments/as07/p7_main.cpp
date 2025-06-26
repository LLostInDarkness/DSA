/*
  Assignment 7: Binary Search Tree
  p7_main.cpp
  Tested/Works

  Purpose: Input what action you want to do (insert, delete, and more)
*/

#include "bst_Funcs.h"
#include <unordered_map>
#include <iostream>

std::pair<std::string, int> split(std::string line_input, std::string line_split = " ") {
  auto index = line_input.find(line_split);
  auto comment = line_input.find("#");
  int key_val = 0;
  int len = line_input.length();

  if(index != std::string::npos && comment == std::string::npos) {
    std::string left_side = line_input.substr(0, index);
    std::string right_side = line_input.substr((index + 1), len - (index + 1));
    key_val = stoi(right_side);
    return std::make_pair(left_side, key_val);
  }
  return std::make_pair(line_input, key_val);
};


std::unordered_map<std::string, int> choices_map {
  {"successor", 0},
  {"predecessor", 1},
  {"min", 2},
  {"max", 3},
  {"insert", 4},
  {"search", 5},
  {"preorder", 6},
  {"inorder", 7},
  {"postorder", 8},
  {"delete", 9},
  {"#", 10},
};

int main() {
  BinarySearchTree bst_input;
  std::string line_input;

  while (getline(std::cin, line_input)) {
    std::pair<std::string, int> values = split(line_input);
    auto itr = choices_map.find(values.first);
    int key_val = values.second;
    int case_val = 10;

    if (itr != choices_map.end()) {
      case_val = itr->second;
    }

    switch (case_val) {
      case 0:   // successor
      if (bst_input.max() == key_val) {
        std::cout << "no successor for " << key_val << std::endl;
      }else if (bst_input.search(key_val)) {
        int check = bst_input.successor(key_val);
        std::cout << key_val << " successor is " << check << "." << std::endl;
      }else{
        std::cout << "no successor for " << key_val << std::endl;
      }
        break;
      case 1:   // predecessor
        if (bst_input.min() == key_val) {
          std::cout << "no predecessor for " << key_val << std::endl;
        }else if (bst_input.search(key_val)) {
          int check = bst_input.predecessor(key_val);
          std::cout << key_val << " predecessor is " << check << "." << std::endl;
        }else{
          std::cout << "no predecessor for " << key_val << std::endl;
        }
        break;
      case 2:   // min
        if(!bst_input.isEmpty()) {
          int min_val = bst_input.min();
          std::cout << "min is " << min_val << std::endl;
        }else{
          std::cout << "tree empty." << std::endl;
        }
        break;
      case 3:   // max
      if(!bst_input.isEmpty()) {
        int max_val = bst_input.max();
        std::cout << "max is " << max_val << std::endl;
      }else{
        std::cout << "tree empty." << std::endl;
      }
        break;
      case 4:   // insert
        bst_input.insert(key_val);
        std::cout << "inserted " << key_val << "." << std::endl;
        break;
      case 5:   // search
        if (bst_input.search(key_val)) {
          std::cout << key_val << " found." << std::endl;
        }else{
          std::cout << key_val << " not found." << std::endl;
        }
        break;
      case 6:   // preorder
        if (!bst_input.isEmpty()) {
          std::cout << "preorder traversal:" << std::endl;
          bst_input.preorder_traversal();
        } else {
          std::cout << "preorder traversal:" << std::endl;
        std::cout << std::endl;
        }
        break;
      case 7:   // inorder
      if (!bst_input.isEmpty()) {
        std::cout << "inorder traversal:" << std::endl;
        bst_input.inorder_traversal();
      } else {
        std::cout << "inorder traversal:" << std::endl;
        std::cout << std::endl;
      }
        break;
      case 8:   // postorder
      if (!bst_input.isEmpty()) {
        std::cout << "postorder traversal:" << std::endl;
        bst_input.postorder_traversal();
      } else {
        std::cout << "postorder traversal:" << std::endl;
        std::cout << std::endl;
      }
        break;
      case 9:   // remove
        if(bst_input.search(key_val)) {
          bst_input.remove(key_val);
          std::cout << "deleted " << key_val << "." << std::endl;
        }else{
          std::cout << "delete " << key_val << " - not found." << std::endl;
        }
        break;
      case 10:  // comment/end program
        break;
      default:
        break;
    }
  }
}