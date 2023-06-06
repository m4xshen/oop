//This menu function is for your reference
#include "Class.h"

// Course

Course::Course() {}

std::vector<std::string> Course::total_vec(0);
std::vector<Course*> Course::total_obj_ptr_vec(0);

Course::Course(std::string name, Teacher* teacher_ptr)
  : name(name), stu_num(0), teacher_num(0) {
  // add a teacher
  Teacher **new_tea_arr = new Teacher*[++teacher_num];
  for (int i = 0; i < teacher_num-1; i++) {
    new_tea_arr[i] = tea_arr[i];
  }
  delete[] tea_arr;
  new_tea_arr[teacher_num-1] = teacher_ptr;
  tea_arr = new_tea_arr;
}

Course::~Course() {
  delete[] tea_arr;
  delete[] stu_arr;
}

void Course::createNewCourse(std::string name, Teacher *teacher_ptr) {
  Course *course = new Course(name, teacher_ptr);
  Course::total_vec.push_back(name);
  Course::total_obj_ptr_vec.push_back(course);

  *teacher_ptr += course;
}

std::ostream& operator<<(std::ostream& out, Course& c) {
  out << "this course is " << c.name << "\n";

  // print teachers
  out << "teacher: ";
  for (int i = 0; i < c.teacher_num; i++) {
    if (i != 0) out << ", ";
    out << c.tea_arr[i]->get_name();
  }
  out << "\n";

  // print students
  out << "student: ";
  for (int i = 0; i < c.stu_num; i++) {
    if (i != 0) out << ", ";
    out << c.stu_arr[i]->get_name();
  }
  out << "\n";

  // print homeworks
  out << "homework: ";
  for (auto it = c.HW_vec.begin(); it != c.HW_vec.end(); it++) {
    if (it != c.HW_vec.begin()) out << ", ";
    out << *it;
  }
  out << "\n";
  return out;
}

// Teacher

std::vector<std::string> Teacher::total_vec(0);
std::vector<Teacher*> Teacher::total_obj_ptr_vec(0);

Teacher::Teacher() : course_num(0) {}

Teacher::Teacher(std::string name, std::string password)
  : course_num(0), name(name), password(password) {
  Teacher::total_vec.push_back(name);
  Teacher::total_obj_ptr_vec.push_back(this);
}

void Teacher::createNewTeacher(std::string name, std::string password) {
  Teacher *tmp = new Teacher(name, password);
}

Teacher::~Teacher() {
  delete[] course_arr;
}

bool Teacher::check_password(std::string input) const {
  return input == password;
}

bool Teacher::menu() {
  std::cout << "----------User Menu----------" << std::endl;
  std::cout << "You have " << course_num << " courses." << std::endl;

  int index = -1;
  for (int i=0; i<course_num; i++) {
    std::cout << (i+1) << ". " << (*(course_arr[i])).name << std::endl;
  }
  std::cout << (course_num+1) << ". Simulate student mode." << std::endl;
  std::cout << (course_num+2) << ". Logout." << std::endl;

  std::string ch_str = "";
  int ch = 0;
  while(ch_str < "1" || ch_str > std::to_string(course_num+2) || ch_str.size() != 1){
    std::cout << "Choice: ";
    std::cin >> ch_str;
  }
  ch = (int)ch_str[0] - 48;
  if(ch == (course_num+2)){
    std::cout << "Back to the Main Menu" << std::endl << std::endl;
    return false;
  }
  else if(ch == (course_num+1)) {
    Simulate_Student_mode();
    return false; // TODO
  }
  else{
    std::cout << "----------Course Menu----------" << std::endl;
    index = ch - 1;
    std::cout << (*(course_arr[index]));

    std::cout << "1. Assign the homework" << std::endl;
    std::cout << "2. Add new teacher" << std::endl;
    std::cout << "3. Previous page." << std::endl;
    ch_str = "";
    ch = 0;
    while(ch_str < "1" || ch_str > "3" || ch_str.size() != 1){
      std::cout << "Choice: ";
      std::cin >> ch_str;
    }
    ch = (int)ch_str[0] - 48;

    if (ch == 1) {
      std::string hw_name;
      std::cout << "Name: ";
      std::cin >> hw_name;
      course_arr[index]->HW_vec.push_back(hw_name);
    } else if (ch == 2) {
      std::string teacher_name;
      std::cout << "Name: ";
      std::cin >> teacher_name;

      // Find the teacher by name
      Teacher *teacher_ptr;
      for (Teacher *t : Teacher::total_obj_ptr_vec) {
        if (t->name == teacher_name) teacher_ptr = t;
      }

      // add course to the teacher
      Course **new_course_arr = new Course*[++(teacher_ptr->course_num)];
      for (int i = 0; i < teacher_ptr->course_num-1; i++) {
        new_course_arr[i] = (teacher_ptr->course_arr)[i];
      }
      delete[] teacher_ptr->course_arr;
      new_course_arr[teacher_ptr->course_num-1] = course_arr[index];
      teacher_ptr->course_arr = new_course_arr;

      // add a teacher
      Teacher **new_tea_arr = new Teacher*[++course_arr[index]->teacher_num];
      for (int i = 0; i < course_arr[index]->teacher_num-1; i++) {
        new_tea_arr[i] = course_arr[index]->tea_arr[i];
      }
      delete[] course_arr[index]->tea_arr;
      new_tea_arr[course_arr[index]->teacher_num-1] = teacher_ptr;
      course_arr[index]->tea_arr = new_tea_arr;
    } else {
      std::cout << "Back to the Main Menu" << std::endl << std::endl;
      menu();
      return false;
    }
  }
  return true;
}

std::string Teacher::get_name() const {
  return name;
}

void Teacher::operator+=(Course *course_ptr) {
  // update course_arr
  Course **new_course_arr = new Course*[++course_num];
  for (int i = 0; i < course_num-1; i++) {
    new_course_arr[i] = course_arr[i];
  }
  delete[] course_arr;
  new_course_arr[course_num-1] = course_ptr;
  course_arr = new_course_arr;
}

Teacher::operator Student() const {
  Student student;
  student.simulate = true;
  student.course_arr = new Course*[course_num];
  for (int i = 0; i < course_num; i++) {
    student.course_arr[i] = course_arr[i];
  }

  return student;
}

void Teacher::Simulate_Student_mode() {
  std::cout << "------------------------\n";
  std::cout << "You are in student mode\n";
  (operator Student()).menu();
}

// Student

std::vector<std::string> Student::total_vec(0);
std::vector<Student*> Student::total_obj_ptr_vec(0);

Student::Student() : course_num(0) {}

Student::Student(std::string name, std::string password)
  : course_num(0), name(name), password(password) {
  if (!simulate) {
    Student::total_vec.push_back(name);
    Student::total_obj_ptr_vec.push_back(this);
  }
}

Student::~Student() {
  delete[] course_arr;
}

bool Student::check_password(std::string input) const {
  return password == input;
}

void Student::createNewStudent(std::string name, std::string password) {
  Student *tmp = new Student(name, password);
}


bool Student::menu() {
  std::cout << "----------User Menu----------" << std::endl;
  std::cout << "You have " << course_num << " courses." << std::endl;
  int index = -1;
  for(int i=0; i<course_num; i++){
    std::cout << (i+1) << ". " << (*(course_arr[i])).name << std::endl;
  }
  std::cout << (course_num+1) << ". Select new course." << std::endl;
  std::cout << (course_num+2) << ". Back to teacher mode." << std::endl;
  std::cout << (course_num+3) << ". Logout." << std::endl;

  std::string ch_str = "";
  int ch = 0;
  while(ch_str < "1" || ch_str > std::to_string(course_num+3) || ch_str.size() != 1){
    std::cout << "Choice: ";
    std::cin >> ch_str;
  }

  ch = (int)ch_str[0] - 48;
  if(ch == (course_num+3)){
    std::cout << "Back to the Main Menu" << std::endl << std::endl;
    return false;
  }
  else if(ch == (course_num+2)){
    if(simulate){
      Back_to_Teacher_mode();
      return false;
    }
    else{
      std::cout << "You are not available to do this" << std::endl << std::endl;;
    }
  }
  else if(ch == (course_num+1)){
    select_course();
  }
  else{
    std::cout << "----------Course Menu----------" << std::endl;
    index = ch - 1;
    std::cout << (*(course_arr[index]));

    std::cout << "1. Previous page." << std::endl;
    ch_str = "";
    ch = 0;
    while(ch_str < "1" || ch_str > "1" || ch_str.size() != 1){
      std::cout << "Choice: ";
      std::cin >> ch_str;
    }
    ch = (int)ch_str[0] - 48;
  }
  return true;
}

void Student::select_course() {
  std::string course_name;
  std::cout << "course name: ";
  std::cin >> course_name;

  Course *course_ptr;
  for (auto c : Course::total_obj_ptr_vec) {
    if (c->name == course_name) course_ptr = c;
  }

  // add a student
  if (!simulate) {
    Student **new_stu_arr = new Student*[++course_ptr->stu_num];
    for (int i = 0; i < course_ptr->stu_num-1; i++) {
      new_stu_arr[i] = course_ptr->stu_arr[i];
    }
    delete[] course_ptr->stu_arr;
    new_stu_arr[course_ptr->stu_num-1] = this;
    course_ptr->stu_arr = new_stu_arr;
  }

  // add a course
  Course **new_course_arr = new Course*[++course_num];
  for (int i = 0; i < course_num-1; i++) {
    new_course_arr[i] = course_arr[i];
  }
  delete[] course_arr;
  new_course_arr[course_num-1] = course_ptr;
  course_arr = new_course_arr;
}

std::string Student::get_name() const {
  return name;
}

void Student::Back_to_Teacher_mode() {
  std::cout << "----------------------------\n";
  std::cout << "You are back to teacher mode\n";
  simulate = false;
}
