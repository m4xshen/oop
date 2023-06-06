#include <iostream>
#include "Personnel.h"

Personnel::Personnel() {}

Personnel::Personnel (string id, string name, string email, string password)
  : id(id), name(name), email(email), password(password) {}

string Personnel::getId() {
  return id;
}

void Personnel::printInfo() {
  std::cout << "id: " << id << "\t" << "Name: " << name << "\t" << "email: " << email;
}
