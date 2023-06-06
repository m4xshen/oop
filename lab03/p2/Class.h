#include <string>

struct Student {
  std::string name;
  std::string student_id;
  int score;
};

class Class {
public:
  Class();
  Class(const Class &);
  void initialize();
  void students_info();
  void score_info() const;
  void set_passing_score(int);
  void set_score(std::string, int);
  void add_student(Student);
  void remove_student(std::string);

private:
  int class_size;
  int passing_score;
  Student *students;
  void set_class_size(int);
  void set_students(Student *);
  int find_student(std::string) const;
  double find_average() const;
  double find_median() const;
  int find_fail() const;
};
