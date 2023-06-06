#include "TA.h"
#include "Course.h"
#include <iostream>

TA::TA(string id, string name, string email, string password, string degree, int tuition, int salary)
  : Personnel(id, name, email, password),
    Student(id, name, email, password, degree, tuition),
    Teacher(id, name, email, password, salary) {}


void TA::printInfo() {
  std::cout << "\t";
  Teacher::printInfo();
  std::cout << "\n\tAttend Courses: ";
  for (Course *course : attendedCourses) {
    std::cout << course->getName() << " ";
  }
}
