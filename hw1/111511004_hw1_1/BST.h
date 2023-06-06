#pragma once

#include <iostream>

struct node{
  void* dataPtr;
  node* left;
  node* right;
};

class BST{
 public:
  BST(int (*compare) (void* argu1, void* argu2));
  ~BST() = default;
  bool BST_Insert(void* dataPtr);
  bool BST_Delete(void* dltKey);
  void BST_Traverse(void (*process) (void* dataPtr));
  bool BST_Empty();

  bool BST_Full();
  int BST_Count();
  node* _insert(node* root, node* newPtr);
  node* _delete(node* root, int dltKey, bool *found);
  void _traverse(node *currentNode, void (*process) (void* dataPtr));
  bool _full(node *root);

 private:
  int count;
  int (*compare) (void* argu1, void* argu2);
  node* root;
};
