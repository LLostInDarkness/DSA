/*
  Rebecca Negrete
  rnegrete
  rnegrete0454@gmail.com
  Assignment 7
  bst.cpp
*/

#include "bst_Funcs.h"

BinarySearchTree::BinarySearchTree() {}  // compiler generated constructor

BinarySearchTree::~BinarySearchTree() {del_tree(root);}

bool BinarySearchTree::search(int key) {
  return search_tree(root, key) != nullptr;
}

void BinarySearchTree::insert(int key) {
  Node* node = new Node;
  node->data = key;

  Node* prev = nullptr;
  Node* temp_root = root;

  while (temp_root != nullptr) {
    prev = temp_root;

    if (node->data < temp_root->data) {
      temp_root = temp_root->left;
    }else{
      temp_root = temp_root->right;
    }
  }

  node->parent = prev;

  if (prev == nullptr) {
    root = node;
    return;
  }
  if (node->data < prev->data) {
    prev->left = node;
  }else{
    prev->right = node;
  }
}

void BinarySearchTree::remove(int key) {remove_node(key);}

bool BinarySearchTree::isEmpty() {return root == nullptr;}

int BinarySearchTree::min() {
  if (isEmpty()) {std::cout << "Empty Tree" << std::endl;}

  Node* node = min_node(root);
  return node->data;
}

int BinarySearchTree::max() {
  if (isEmpty()) {std::cout << "Empty Tree" << std::endl;}

  Node* node = max_node(root);
  return node->data;
}

int BinarySearchTree::predecessor(int key) {
  if(!search(key)) {
    std::cout << "key not found" << std::endl;
  }

  Node* node = predecessor_node(root, key);
  return node->data;
}

int BinarySearchTree::successor(int key) {
  if(!search(key)) {
    std::cout << "key not found" << std::endl;
  }

  Node* node = successor_node(root, key);
  return node->data;
}

void BinarySearchTree::inorder_traversal() {
  inorder_helper(root);
  std::cout << std::endl;
}

void BinarySearchTree::preorder_traversal() {
  preorder_helper(root);
  std::cout << std::endl;
}

void BinarySearchTree::postorder_traversal() {
  postorder_helper(root);
  std::cout << std::endl;
}

// private functions & helpers to public functions
BinarySearchTree::Node* BinarySearchTree::search_tree(Node* node, int key) {
  if (node == nullptr || node->data == key) {
    return node;
  }

  if(key < node->data) {
    return search_tree(node->left, key);
  }else{
    return search_tree(node->right, key);
  }
}

BinarySearchTree::Node* BinarySearchTree::min_node(Node* node) {
  if(node == nullptr) {return nullptr;}

  while(node->left != nullptr) {
    node = node->left;
  }

  return node;
}

BinarySearchTree::Node* BinarySearchTree::max_node(Node* node) {
  if(node == nullptr) {return nullptr;}

  while(node->right != nullptr) {
    node = node->right;
  }
  
  return node;
}

BinarySearchTree::Node* BinarySearchTree::predecessor_node(Node* nodes, int key) {
  Node* node = search_tree(nodes, key);

  if(node == nullptr) {return nullptr;}
  if(node->left) {return max_node(node->left);}

  Node* temp_node = node->parent;

  while(temp_node && node == temp_node->left) {
    node = temp_node;
    temp_node = temp_node->parent;
  }

  return temp_node;
}

BinarySearchTree::Node* BinarySearchTree::successor_node(Node* nodes, int key) {
  Node* node = search_tree(nodes, key);

  if(node == nullptr) {return nullptr;}
  if(node->right) {return min_node(node->right);}

  Node* temp_node = node->parent;

  while(temp_node && node == temp_node->right) {
    node = temp_node;
    temp_node = temp_node->parent;
  }
  
  return temp_node;
}

void BinarySearchTree::del_tree(Node* node) {
  if (node != nullptr) {
    del_tree(node->left);
    del_tree(node->right);
    delete node;
  }
}

void BinarySearchTree::remove_node(int key) {
  Node* node = search_tree(root, key);

  if (node == nullptr) {return;}

  Node* hold = node;

  if (node->left && node->right) {hold = successor_node(node, key);}

  Node* temp_node = nullptr;

  if (hold->left) {
    temp_node = hold->left;
  }else{
    temp_node = hold->right;
  }

  if (temp_node) {
    temp_node->parent = hold->parent;
  }

  if (hold->parent == nullptr) {
    root = temp_node; 
  }else if (hold == hold->parent->left) {
      hold->parent->left = temp_node;
  }else{
    hold->parent->right = temp_node;
  }

  if (hold != node) {
    node->data = hold->data;
  }
  delete hold;
}

void BinarySearchTree::inorder_helper(Node* node) {
  if(node != nullptr) {
    inorder_helper(node->left);
    std::cout << node->data << " ";
    inorder_helper(node->right);
  }
}

void BinarySearchTree::preorder_helper(Node* node) {
  if(node != nullptr) {
    std::cout << node->data << " ";
    preorder_helper(node->left);
    preorder_helper(node->right);
  }
}

void BinarySearchTree::postorder_helper(Node* node) {
  if(node != nullptr) {
    postorder_helper(node->left);
    postorder_helper(node->right);
    std::cout << node->data << " ";
  }
}