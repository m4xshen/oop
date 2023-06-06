#include <string>
#include <vector>
#include <iostream>

class Teacher;
class Student;
class Course;

class Course {
 private:
  int stu_num;
  int teacher_num;
  std::string name;
  Teacher **tea_arr;
  Student **stu_arr;
  std::vector<std::string> HW_vec;

 public:
  static std::vector<std::string> total_vec;
  static std::vector<Course*> total_obj_ptr_vec;
  static void createNewCourse(std::string name, Teacher* teacher_ptr);

  friend class Teacher;
  friend class Student;
  Course();
  Course(std::string name, Teacher* teacher_ptr);
  ~Course();
  
  friend std::ostream& operator<<(std::ostream& out, Course& c);
};

class Teacher {
 private:
  int course_num;
  std::string name;
  Course **course_arr;
  const std::string password;

 public:
  static std::vector<std::string> total_vec;
  static std::vector<Teacher*> total_obj_ptr_vec;
  static void createNewTeacher(std::string name, std::string password);

  Teacher();
  Teacher(std::string name, std::string password);
  ~Teacher();
  bool check_password(std::string input) const;
  bool menu();
  std::string get_name() const;
  void operator+=(Course *course_ptr);
  
  operator Student() const;
  void Simulate_Student_mode();
};

class Student {
 private:
  int course_num;
  std::string name;
  const std::string password;
  Course **course_arr;

  bool simulate;
  
 public:
  static std::vector<std::string> total_vec;
  static std::vector<Student*> total_obj_ptr_vec;
  static void createNewStudent(std::string name, std::string password);

  friend class Teacher;
  Student();
  Student(std::string name, std::string password);
  ~Student();
  bool check_password(std::string input) const;
  bool menu();
  void select_course();
  std::string get_name() const;

  void Back_to_Teacher_mode();
};
