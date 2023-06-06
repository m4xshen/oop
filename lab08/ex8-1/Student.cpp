#include "Student.h"
#include "Course.h"
#include <iostream>

Student::Student(string id, string name, string email, string password, string degree, int tuition)
  : Personnel(id, name, email, password), degree(degree), tuition(tuition) {}


void Student::printInfo() {
  std::cout << "\t";
  Personnel::printInfo();
  std::cout << "\tDegree: " << degree << "\tTuition: " << tuition;
  std::cout << "\n\tAttend Courses: ";
  for (Course *course : attendedCourses) {
    std::cout << "\"" << course->getName() << "\" ";
  }
}

void Student::addAttendCourse(Course *course) {
  attendedCourses.push_back(course);
}
