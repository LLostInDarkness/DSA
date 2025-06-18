/*
  Rebecca Negrete
  rnegrete0454@gmail.com
  Assignment 7
  bst_Funcs.h
*/

#include <iostream>
// #include <unordered_map>

class BinarySearchTree {
  public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool search(int key);
    void insert(int key);
    void remove(int key);
    bool isEmpty();
    int min();
    int max();
    int predecessor(int key);
    int successor(int key);
    void inorder_traversal();
    void preorder_traversal();
    void postorder_traversal();
  private:
    struct Node {
      Node* left = nullptr;
      Node* right = nullptr;
      Node* parent = nullptr;
      int data;
    };
    Node* root = nullptr;

    // helper functions for public functions
    Node* search_tree(Node* node, int key);
    Node* min_node(Node*);
    Node* max_node(Node*);
    Node* predecessor_node(Node*, int key);
    Node* successor_node(Node*, int key);

    void del_tree(Node*);
    void remove_node(int key);
    void inorder_helper(Node*);
    void preorder_helper(Node*);
    void postorder_helper(Node*);

};