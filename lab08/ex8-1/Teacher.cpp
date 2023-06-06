#include <iostream>
#include "Teacher.h"
#include "Course.h"

Teacher::Teacher(string id, string name, string email, string password, int salary)
  : Personnel(id, name, email, password), salary(salary) {}

void Teacher::addTaughtCourse(Course* course) {
  taughtCourses.push_back(course);
}

void Teacher::printInfo() {
  Personnel::printInfo();
  std::cout << "\tSalary: " << salary << "\n";

  std::cout << "\tTaught Courses: ";
  for (Course *course : taughtCourses) {
    std::cout << '"' << course->getName() << "\" ";
  }
}
