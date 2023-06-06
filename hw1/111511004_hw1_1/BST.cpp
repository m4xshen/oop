#include "BST.h"

BST::BST(int (*compare) (void* argu1, void* argu2)) {
  this->compare = compare;
  root = nullptr;
  count = 0;
}

node *BST::_insert(node *root, node *newPtr) {
  if (!root) return newPtr;

  if (compare(newPtr->dataPtr, root->dataPtr)) {
    root->left = _insert(root->left, newPtr);
  } else {
    root->right = _insert(root->right, newPtr);
  }

  return root;
}

bool BST::BST_Insert(void *dataPtr) {
  count++;

  // create new node
  node *newNode = new node;
  int *data = new int;
  *data = *((int*)dataPtr);
  newNode->dataPtr = data;

  root = _insert(root, newNode);

  return true;
}

node *BST::_delete(node *root, int dltKey, bool *found) {
  if (!root) return root;

  if (dltKey < *((int*)root->dataPtr)) {
    root->left = _delete(root->left, dltKey, found);
  } else if (dltKey > *((int*)root->dataPtr)) {
    root->right = _delete(root->right, dltKey, found);
  } else { // delete this node
    *found = true;

    node *tmp = root->right;
    if (!root->left && !root->right) {
      return nullptr;
    } else if (!root->right) {
      tmp = root->left;
    }

    if (!root->left || !root->right) {
      delete root;
      return tmp;
    }

    while (tmp->left) { tmp = tmp->left; }
    root->dataPtr = tmp->dataPtr;
    root->right = _delete(root->right, *((int *)tmp->dataPtr), found);
  }

  return root;
}

bool BST::BST_Delete(void *dltKey) {
  bool found = false;
  root = _delete(root, *((int*)dltKey), &found);
  if (found) count--;

  return found;
}

void BST::_traverse(node *currentNode, void (*process)(void *)) {
  if (!currentNode) return;
  _traverse(currentNode->left, process);
  process(currentNode->dataPtr);
  _traverse(currentNode->right, process);
}

void BST::BST_Traverse(void (*process) (void* dataPtr)) {
  if (count == 0) {
    std::cout << "The BST is empty.";
    return;
  }
  _traverse(root, process);
}

int BST::BST_Count() {
  return count;
}

bool BST::_full(node *root) {
  if (!root) return true;

  // the root has only one child
  if ((root->left && !root->right) || (root->right && !root->left)) {
    return false;
  }
  return _full(root->left) && _full(root->right);
}

bool BST::BST_Full() {
  return _full(root);
}
