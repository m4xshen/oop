#include "Class.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

Class::Class() {}
Class::Class(const Class &pt)
  : class_size(pt.class_size), passing_score(pt.passing_score) {
  students = new Student[class_size];
  std::copy(pt.students, pt.students+class_size, students);
}

void Class::initialize() {
  int cs;
  std::cout << "Number of students: "; std::cin >> cs;
  set_class_size(cs);

  int ps;
  std::cout << "Set Passing Score: "; std::cin >> ps;
  set_passing_score(ps);

  Student *tmp = new Student[class_size];
  std::for_each(tmp, tmp+class_size, [](Student &s) {
    std::cout << "Student Name: ";
    std::cin >> s.name;
    std::cout << "Student ID: ";
    std::cin >> s.student_id;
    std::cout << "Score: ";
    std::cin >> s.score;
  });

  set_students(tmp);
  delete[] tmp;
}

void Class::set_class_size(int size) {
  class_size = size;
}

void Class::set_students(Student *tmp) {
  students = new Student[class_size];
  std::copy(tmp, tmp+class_size, students);
}

void Class::students_info() {
  if(students == nullptr) {
    std::cout << "student doesn't exist!\n";
    return;
  }

  std::sort(students, students+class_size,
    [](const Student &s1, const Student &s2) {
      return s1.student_id.compare(s2.student_id) < 0;
    });

  std::for_each(students, students+class_size, [](const Student &s) {
    std::cout << s.name << "\t" << s.student_id << "\t" << s.score << "\n";
  });
  std::cout << "\n";
}

void Class::add_student(Student student) {
  Student *new_students = new Student[class_size+1];
  std::copy(students, students+class_size, new_students);
  new_students[class_size++] = student;

  delete[] students;
  students = new_students;
}

void Class::score_info() const {
  std::cout << "Average Score: " << find_average() << "\n";
  std::cout << "Median Score: " <<  find_median() << "\n";
  std::cout << "Fail Student Number: " << find_fail() << "\n\n";
}

double Class::find_average() const {
  return (double)std::accumulate(students, students+class_size, 0,
      [](int t, const Student &s) { return t + s.score; }) / class_size;
}

double Class::find_median() const {
  std::sort(students, students+class_size,
      [](const Student &s1, const Student &s2) { return s1.score < s2.score; });

  if(class_size & 1) // class_size is odd
    return (double)students[(int)((class_size-1)/2)].score;

  return ((double)students[(int)(class_size/2)].score
      + (double)students[(int)(class_size/2)-1].score) / 2;
}

int Class::find_fail() const {
  return std::count_if(students, students+class_size,
      [=](const Student &s) { return s.score < passing_score; });
}

void Class::set_score(std::string name, int score) {
  Student *f = std::find_if(students, students+class_size,
      [=](const Student &s) { return s.name == name; });
  if(f != students+class_size) f->score = score;
}

void Class::set_passing_score(int p_score) {
  passing_score = p_score;
}

int Class::find_student(std::string name) const {
  Student *f = std::find_if(students, students+class_size,
      [=](const Student &s) { return s.name == name; });

  if(f == students+class_size) {
    std::cout << "student doesn't exist!\n";
    return -1;
  }
  return f - students;
}

void Class::remove_student(std::string name) {
  if(find_student(name) == -1) return;

  Student *tmp = new Student[--class_size];
  std::copy_if(students, students+class_size+1, tmp,
      [=](Student s) { return s.name != name; });
  set_students(tmp);

  delete[] tmp;
}
