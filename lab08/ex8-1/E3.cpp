#include "E3.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void E3::importPersonnelsFromCsv(string csvFilename) {
  std::fstream file;
  file.open(csvFilename);

  std::string line;
  getline(file, line);
  while (getline(file, line)) {
    std::stringstream ss(line);

    std::string id, name, email, password, position, degree, tuition_string, salary_string;
    int tuition, salary;
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, email, ',');
    getline(ss, password, ',');
    getline(ss, position, ',');
    getline(ss, degree, ',');
    getline(ss, tuition_string, ',');
    getline(ss, salary_string, ',');

    if (tuition_string == "") {
      tuition_string = "-1";
    }
    if (salary_string == "") {
      salary_string = "-1";
    }

    tuition = std::stoi(tuition_string);
    salary = std::stoi(salary_string);

    if (position == "Student") {
      Student *s = new Student(id, name, email, password, degree, tuition);
      students.push_back(s);
      Personnel *p = s;
      personnels.push_back(p);
    }

    if (position == "Teacher") {
      Teacher *t = new Teacher(id, name, email, password, salary);
      teachers.push_back(t);
      Personnel *p = t;
      personnels.push_back(p);
    }

    if (position == "TA") {
      TA *ta = new TA(id, name, email, password, degree, tuition, salary);
      TAs.push_back(ta);

      Personnel *p = ta;
      personnels.push_back(p);
    }
  }
}

void E3::importCoursesFromCsv(string csvFilename) {
  std::fstream file;
  file.open(csvFilename);

  std::string line;
  getline(file, line);
  while (getline(file, line)) {
    std::stringstream ss(line);

    std::string id, name, professor_id, ta_ids, student_ids;
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, professor_id, ',');
    getline(ss, ta_ids, ',');
    getline(ss, student_ids, ',');

    for (Teacher *t : teachers) {
      if (t->getId() != professor_id) continue;

      Course *course = new Course(id, name, t);
      courses.push_back(course);
      t->addTaughtCourse(course);

      ss.clear();
      ss.str("");
      ss << ta_ids;
      std::string ta_id;
      while(getline(ss, ta_id, '|')) {
        for (TA *ta : TAs) {
          if (ta->getId() != ta_id) continue;
          course->addTA(ta);
          ta->addTaughtCourse(course);
          break;
        }
      }
      
      ss.clear();
      ss.str("");
      ss << student_ids;
      std::string student_id;
      while(getline(ss, student_id, '|')) {
        for (Student *student : students) {
          if (student->getId() != student_id) continue;
          course->addStudent(student);
          student->addAttendCourse(course);
          break;
        }

        for (Student *student : TAs) {
          if (student->getId() != student_id) continue;
          course->addStudent(student);
          student->addAttendCourse(course);
          break;
        }
      }
      
      break;
    }
  }
}

void E3::printAllPersonnel() {
  for (Personnel *personnel : personnels) {
    personnel->printInfo();
    std::cout << "\n";
  }
}

void E3::printAllCourse() {
  for (Course *course : courses) {
    course->printInfo();
    std::cout << "\n";
  }
}

E3::~E3() {}
