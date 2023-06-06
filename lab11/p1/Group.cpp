#include <iomanip>
#include <iostream>
#include <algorithm>
#include "Group.h"
#include "Student.h"

Group::Group()
: student_num(0),
  sum_score_Calculus(0), sum_score_English(0), sum_score_Physics(0),
  high_Calculus(0), high_English(0), high_Physics(0), 
  low_Calculus(100), low_English(100), low_Physics(100) {}

Group::~Group() {}

void Group::addStudent(Student student) {
  students.push_back(student);
  student_num++;
  calcScores();
}

void Group::calcScores() {
  sum_score_Calculus = 0, sum_score_English = 0, sum_score_Physics = 0;
  high_Calculus = 0, high_English = 0, high_Physics = 0; 
  low_Calculus = 100, low_English = 100, low_Physics = 100;

  for (Student s : students) {
    high_Calculus = std::max(high_Calculus, s.get_scores()[0]);
    high_English = std::max(high_English, s.get_scores()[1]);
    high_Physics = std::max(high_Physics, s.get_scores()[2]);

    low_Calculus = std::min(low_Calculus, s.get_scores()[0]);
    low_English = std::min(low_English, s.get_scores()[1]);
    low_Physics = std::min(low_Physics, s.get_scores()[2]);

    sum_score_Calculus += s.get_scores()[0];
    sum_score_English += s.get_scores()[1];
    sum_score_Physics += s.get_scores()[2];
  }
}

void Group::removeStudentByName(std::string name) {
  auto f = std::remove_if(students.begin(), students.end(),
    [=](Student s) { return s.get_name() == name; });

  if (f == students.end()) {
    std::cout << "Student doesn't exist.\n";
    return;
  }

  std::cout << "Remove Successfully\n";
  students.erase(f);
  student_num--;
  sum_score_Calculus -= f->get_scores()[0];
  sum_score_English -= f->get_scores()[1];
  sum_score_Physics -= f->get_scores()[2];
  calcScores();
}

void Group::removeStudentByID(std::string id) {
  auto f = std::remove_if(students.begin(), students.end(),
    [=](Student s) { return s.get_id() == id; });

  if (f == students.end()) {
    std::cout << "Student doesn't exist.\n";
    return;
  }

  std::cout << "Remove Successfully\n";
  students.erase(f);
  student_num--;
  sum_score_Calculus -= f->get_scores()[0];
  sum_score_English -= f->get_scores()[1];
  sum_score_Physics -= f->get_scores()[2];
  calcScores();
}

void Group::gradeDistribution() {
  std::cout << std::fixed << std::setprecision(2);

  std::cout << "Student Num: " << student_num << "\n";
  std::cout << "<Calculus>\n";
  std::cout << "Avg: " << (double)sum_score_Calculus / student_num << "\n";
  std::cout << "Max: " << high_Calculus << "\n";
  std::cout << "Min: " << low_Calculus << "\n";

  std::cout << "<English>\n";
  std::cout << "Avg: " << (double)sum_score_English / student_num << "\n";
  std::cout << "Max: " << high_English << "\n";
  std::cout << "Min: " << low_English << "\n";

  std::cout << "<Physics>\n";
  std::cout << "Avg: " << (double)sum_score_Physics / student_num << "\n";
  std::cout << "Max: " << high_Physics << "\n";
  std::cout << "Min: " << low_Physics << "\n\n";
}

int Group::get_student_num() const {
  return student_num;
}

std::vector<Student> Group::get_students() const {
  return students;
}
