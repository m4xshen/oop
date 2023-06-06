#include <iostream>
#include <algorithm>
#include "EEE.h"
#include "Student.h"
#include "Group.h"

EEE::EEE() {}

EEE::~EEE() {}

void EEE::addStudent(std::string group_name, Student student) {
  groups.insert({group_name, {}});
  groups[group_name].addStudent(student);
}

void EEE::removeStudentByID(std::string group_name, std::string id) {
  if (groups[group_name].get_student_num() == 0) {
    std::cout << "Group doesn't exist\n";
    return;
  }
  groups[group_name].removeStudentByID(id);
}

void EEE::removeStudentByName(std::string group_name, std::string name) {
  if (groups[group_name].get_student_num() == 0) {
    std::cout << "Group doesn't exist\n";
    return;
  }
  groups[group_name].removeStudentByName(name);
}

void EEE::gradeDistribution(std::string group_name) {
  if (groups[group_name].get_student_num() == 0) {
    std::cout << "Group doesn't exist\n";
    return;
  }

  groups[group_name].gradeDistribution();
}

void EEE::viewInfo(std::string group_name, int mode) {
  if (groups.find(group_name) == groups.end()) {
    std::cout << "Group doesn't exist\n";
    return;
  }

  std::vector<Student> students = groups[group_name].get_students();

  if (mode == 1) {
    std::sort(students.begin(), students.end(),
      [](Student s1, Student s2) { return s1.get_id() < s2.get_id(); });
  } else if (mode == 2) {
    std::sort(students.begin(), students.end(),
      [](Student s1, Student s2) { return s1.get_name() < s2.get_name(); });
  }

  std::cout << "Student Num: " << groups[group_name].get_student_num() << "\n";
  int n = groups[group_name].get_student_num();
  for (int i = 1; i <= n; i++) {
    std::cout << "<Student " << i << "> " << students[i-1];
  }
}
