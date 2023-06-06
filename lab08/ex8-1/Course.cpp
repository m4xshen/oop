#include <iostream>
#include "Course.h"
#include "TA.h"

Course::Course(string id, string name, Teacher* teacher)
  : id(id), name(name), teacher(teacher) {}

void Course::addTA(TA* ta) {
  TAs.push_back(ta);
}

void Course::addStudent(Student* student) {
  students.push_back(student);
}

void Course::printInfo() {
  std::cout << "id: " << id << "\t" << "Name: " << name << "\n";
  std::cout << "Teacher:\n\t";
  teacher->printInfo();

  std::cout << "\nTAs:\n";
  for (TA *ta : TAs) {
    ta->printInfo();
    std::cout << "\n\n";
  }

  std::cout << "\nStudents:\n";
  for (Student *student : students) {
    student->printInfo();
    std::cout << "\n\n";
  }
}

std::string Course::getName() {
  return name;
}
