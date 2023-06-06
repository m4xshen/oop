#include <map>
#include <string>
#include <vector>

class Student;
class Group;

class EEE {
 public:
  EEE();
  ~EEE();
  void addStudent(std::string, Student);          // add student to the group
  void removeStudentByID(std::string, std::string);    // remove student from the group by ID
  void removeStudentByName(std::string, std::string);  // remove student from the group by Name
  void gradeDistribution(std::string);            // show grade distribution of the group
  void viewInfo(std::string, int);                // view student info of the group, int represent diff mode
  // 0: sort by insertion time, 1: sort by ID, 2: sort by name

 private:
  std::map<std::string, Group> groups;
};
