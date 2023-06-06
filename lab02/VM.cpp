#include "VM.h"
#include <iostream>
#include <string>
#include <algorithm>

void VM::add_item() {
  std::cout << "Please enter the information of the item.\n";

  int id, price;
  std::string name;

  std::cout << "ID: ";
  std::cin >> id;
  std::cout << "Name: ";
  std::cin >> name;
  std::cout << "Price: ";
  std::cin >> price;

  item it;
  it.id = id;
  it.name = name;
  it.price = price;
  item_vec.push_back(it);
}

void VM::remove_item() {
  std::string name;
  std::cout << "The name of the item you want to remove: ";
  std::cin >> name;

  for(auto it = item_vec.begin(); it != item_vec.end(); it++) {
    if(it->name == name) { // found
      item_vec.erase(it);
      return;
    }
  }

  std::cout << "No item found!\n";
}

void VM::find_change(int total) {
  std::cout << "Your change\n";
  int r1, r5, r10, r50;
  r50 = total / 50;
  total %= 50;
  r10 = total / 10;
  total %= 10;
  r5 = total / 5;
  total %= 5;
  r1 = total;

  std::cout << "One dollar: " << r1 << "\n";
  std::cout << "Five dollar: " << r5 << "\n";
  std::cout << "Ten dollar: " << r10 << "\n";
  std::cout << "Fifty dollar: " << r50 << "\n";
}

void VM::purchase_item() {
  std::string name;
  std::cout << "Which item do you want to buy?\n";
  std::cin >> name;

  for(auto it = item_vec.begin(); it != item_vec.end(); it++) {
    int c1, c5, c10, c50;
    if(it->name == name) {
      std::cout << "The price is " << it->price << " dollars\n";
      std::cout << "Please insert coins.\n";
      std::cout << "One dollar: ";
      std::cin >> c1;
      std::cout << "Five dollar: ";
      std::cin >> c5;
      std::cout << "Ten dollar: ";
      std::cin >> c10;
      std::cout << "Fifty dollar: ";
      std::cin >> c50;

      int total = c1 + 5*c5 + 10*c10 + 50*c50;
      if(total == it->price) {
        std::cout << "No change should be given.\n";
      }
      else {
        find_change(total - it->price);
      }

      item_vec.erase(it);
      std::cout << "Thank you for your purchase!\n";
      return;
    }
  }

  std::cout << "Out of stock!\n";
}

int comp(item a, item b) {
  return a.id < b.id;
}

void VM::print_itemList() {
  if(item_vec.empty()) {
    std::cout << "There is no item right now!!!\n";
    return;
  }

  std::cout << "ID\tName\tPrice\n";
  sort(item_vec.begin(), item_vec.end(), comp);
  for(auto it : item_vec) {
    std::cout << it.id << "\t" << it.name << "\t" << it.price << "\n";
  }
}

void VM::print_optionList() {
  std::cout << "1. Add item\n";
  std::cout << "2. Remove item\n";
  std::cout << "3. Print item list\n";

  int option;
  std::cin >> option;

  if(option == 1) add_item();
  else if(option == 2) remove_item();
  else if(option == 3) print_itemList();
}

std::string VM::set_password() {
  std::string pw, pw_again;
  while(1) {
    std::cout << "Enter a password for your vending machine: ";
    std::cin >> pw;
    std::cout << "Enter your password again: ";
    std::cin >> pw_again;

    if(pw == pw_again) {
      break;
    }
    else {
      std::cout << "It's different from the first password! Please set the password again!\n";
    }
  }

  return pw;
}

void VM::start() {
  password = set_password();

  while(1) { // main loop
    int mode;
    while(1) {
      std::cout << "Enter 1 for owner mode, 2 for customer mode: ";
      std::cin >> mode;
      if(mode != 1 && mode != 2) {
        std::cout << "Invalid input!\n";
      }
      else {
        break;
      }
    }

    if(mode == 1) { // owner mode
      bool back = false;
      while(1) { // enter password
        std::string pw;
        std::cout << "Please enter your password: ";
        std::cin >> pw;
        if(pw == password) break;
        else {
          int option;
          std::cout << "Wrong password!\n";
          std::cout << "Enter 1 for type again, 2 for going back to last step: ";
          std::cin >> option;

          if(option == 2) {
            back = true;
            break;
          }
        }
      }

      if(back) continue;

      std::cout << "Welcome to owner mode!\n";
      print_optionList();
    }
    else if(mode == 2) { // customer mode
      std::cout << "Welcome! Here is the item list.\n";
      print_itemList();

      if(!item_vec.empty()) {
        purchase_item();
      }
    }
  }
}
