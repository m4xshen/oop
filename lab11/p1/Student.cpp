#include <iostream>
#include "Student.h"

Student::Student(std::string id, std::string name, std::vector<int> scores)
  : id(id), name(name), scores(scores) {}

Student::~Student() {}

std::ostream &operator<<(std::ostream &out, const Student a) {
  out << "ID: " << a.get_id() << ", Name: " << a.get_name() << "\n";
  std::cout << "Scores >\n";
  std::cout << "\t" << "Calculus: " << a.get_scores()[0] << "\n";
  std::cout << "\t" << "English: " << a.get_scores()[1] << "\n";
  std::cout << "\t" << "Physics: " << a.get_scores()[2] << "\n\n";

  return out;
}

std::string Student::get_name() const {
  return name;
}

std::string Student::get_id() const {
  return id;
}

std::vector<int> Student::get_scores() const {
  return scores;
}
