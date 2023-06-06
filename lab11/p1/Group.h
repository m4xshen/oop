#include <string>
#include <vector>

class Student;

class Group {
 public:
  Group();
  ~Group();
  void addStudent(Student);
  void removeStudentByID(std::string);
  void removeStudentByName(std::string);
  void gradeDistribution();  // print out Avg, Max, Min Score of each subject

  int get_student_num() const;
  std::vector<Student> get_students() const;

  // add any function you need

 private:
  void calcScores();
  std::vector<Student> students;
  int student_num;

  int sum_score_Calculus;
  int high_Calculus;
  int low_Calculus;

  int sum_score_English;
  int high_English;
  int low_English;

  int sum_score_Physics;
  int high_Physics;
  int low_Physics;
};
