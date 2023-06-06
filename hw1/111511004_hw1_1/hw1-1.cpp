#include "BST.h"

int compareInt(void* num1, void* num2);
void printBST(void* num1);
void printMenu();

int main() {
  BST bst(compareInt);

  while(true) {
    printMenu();
    std::cout << "Please enter: ";
    short op;
    std::cin >> op;

    if (op == 1) {
      int num;
      std::cout << "Enter an interger: ";
      std::cin >> num;
      bst.BST_Insert(&num);
    } else if (op == 2) {
      int num;
      std::cout << "Enter an interger: ";
      std::cin >> num;
      if (bst.BST_Delete(&num)) {
        if (bst.BST_Count()) {
          std::cout << "New BST: ";
          bst.BST_Traverse(printBST);
        } else {
          std::cout << "The BST is empty.";
        }
        std::cout << "\n";
      } else {
        std::cout << "The number is not in BST.\n";
      }
    } else if (op == 3) {
      bst.BST_Traverse(printBST);
      std::cout << "\n";
    } else if (op == 4) {
      std::cout << "BST is " << (bst.BST_Full() ? "full" : "not full yet") << "\n";
    } else if (op == 5) {
      std::cout << "There are " << bst.BST_Count() << " nodes in BST." << "\n";
    } else if (op == 6){
      break;
    }
  }

  return 0;
}

int compareInt(void* num1, void* num2) {
  return *((int*)num1) < *((int*)num2);
}

void printBST(void* num1) {
  std::cout << *((int*)num1) << " ";
}

void printMenu() {
  std::cout << "The following are six options for your BST:\n";
  std::cout << "1. Insert\n";
  std::cout << "2. Delete\n";
  std::cout << "3. Print the BST\n";
  std::cout << "4. Check the BST is full or not\n";
  std::cout << "5. Print the number of nodes in BST\n";
  std::cout << "6. Exit\n";
}
