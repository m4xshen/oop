#include <string>
#include <vector>

class Student {
 public:
  Student(std::string, std::string, std::vector<int>);  // (ID, Name, Scores)
  ~Student();
  friend std::ostream &operator<<(std::ostream &out, const Student a);
  // add any function you need

  std::string get_name() const;
  std::string get_id() const;
  std::vector<int> get_scores() const;

 private:
  std::string id;
  std::string name;
  std::vector<int> scores;  // store 3 score {Calculus, English, Physics}
};
