#include <iostream>
#include <fstream>

class Mood;
class Student;
class Gift;

class Gift {
public:
  Gift(std::string gift_name, bool good) : gift_name(gift_name), good(good) { }

  std::string gift_name;
  bool good;
  bool given = false;
};

class Student {
public:
  Student(std::string name, std::string want_name, Gift *give)
      : name(name), want_name(want_name), give(give) { }
  Student *insert(Student *);

  int mood_point = 0;
  std::string name;
  std::string want_name;
  Gift *give = nullptr;
  Gift *get = nullptr;
  Student *link = nullptr;
};

class Mood {
public:
  Mood(int mood_point) : mood_point(mood_point) { }
  Mood *insert(Mood *);
  Student *remove(Mood *, std::string);

  int mood_point;
  Mood *link = nullptr;
  Student *head = nullptr;
};

Mood *Mood::insert(Mood *list_head_node) {
  if(list_head_node == nullptr) return this;

  if(list_head_node->mood_point > this->mood_point) {
    this->link = list_head_node;
    return this;
  }

  Mood *prev = list_head_node;
  Mood *curr = list_head_node;

  for(; curr!=nullptr && curr->mood_point<=this->mood_point;
  prev = curr, curr = curr->link) { }

  prev->link = this;
  this->link = curr;

  return list_head_node;
}

Student *Mood::remove(Mood *mood, std::string name) {
  Student *prev = mood->head;
  Student *curr = mood->head;

  for(; curr!=nullptr && curr->name!=name; prev = curr, curr = curr->link) { }

  if(curr == prev) {
    Student *tmp = curr->link;
    curr->link = nullptr;
    return tmp;
  }
  else {
    if(curr == nullptr) prev->link = nullptr;
    else prev->link = curr->link;
    curr->link = nullptr;

    return mood->head;
  }
}

Student *Student::insert(Student *head) {
  if(head == nullptr) return this;

  if(head->name.compare(this->name) > 0) {
    this->link = head;
    return this;
  }

  Student *prev = head;
  Student *curr = head;

  for(; curr!=nullptr && curr->name.compare(this->name)<=0;
  prev = curr, curr = curr->link) { }

  prev->link = this;
  this->link = curr;

  return head;
}

Student *find_student(Mood *list_head_node, std::string name) {
  for(Mood *mood = list_head_node; mood != nullptr; mood = mood->link) {
    for(Student *student = mood->head; student != nullptr; student = student->link) {
      if(student->name == name) return student;
    }
  }
  return nullptr;
}

Mood *find_mood(Mood *list_head_node, int mood_point) {
  for(Mood *mood = list_head_node; mood != nullptr; mood = mood->link) {
    if(mood->mood_point == mood_point) return mood;
  }
  return nullptr;
}

void print(Mood *list_head_node) {
  for(Mood *mood = list_head_node; mood != nullptr; mood = mood->link) {
    if(mood->head != nullptr) std::cout << mood->mood_point;
    for(Student *student = mood->head; student != nullptr; student = student->link) {
      std::cout << " -> " << student->name << "(";
      if(student->get == nullptr) std::cout << "0)";
      else std::cout << student->get->gift_name << ")";
    }
    if(mood->head != nullptr) std::cout << "\n";
  }
  std::cout << "\n";
}

int main(int argc, char **argv) {
  std::ifstream fin(argv[1]);

  std::string input_student[100];
  std::string input_gift[100];
  int len = 0;

  Mood *list_head_node = nullptr;
  Mood *mood0;

  int n;
  fin >> n;

  for(int i = -2; i <= 2; i++) {
    Mood *mood = new Mood(i);
    if(i == 0) mood0 = mood;
    list_head_node = mood->insert(list_head_node);
  }

  std::string name, want_name, gift_name;
  for(int i = 0; i < n; i++) {
    bool good;

    fin >> name >> want_name >> gift_name >> good;
    input_student[len]= name;
    input_gift[len++] = gift_name;
    Student *student = new Student(name, want_name, new Gift(gift_name, good));

    mood0->head = student->insert(mood0->head);
  }

  print(list_head_node);

  // part 1
  while(fin >> name) {
    Student *curr = find_student(list_head_node, name);
    Student *want = find_student(list_head_node, curr->want_name);

    if(!want->give->given) {
      Mood *mood = find_mood(list_head_node, curr->mood_point);
      mood->head = mood->remove(mood, name);

      want->give->given = true;
      curr->get = want->give;

      Mood *to = find_mood(list_head_node, curr->get->good ? 2 : -2);
      curr->mood_point = curr->get->good ? 2 : -2;
      to->head = curr->insert(to->head);
    }
  }
  print(list_head_node);

  // part 2
  for(int i = 0, j = 0; i < len && j < len; i++, j++) {
    Student *student = find_student(list_head_node, input_student[i]);
    while(student->get != nullptr) {
      i++;
      student = find_student(list_head_node, input_student[i]);
    }

    Student *giver;
    for(Mood *mood = list_head_node; mood != nullptr; mood = mood->link) {
      bool flag = false;
      for(Student *s = mood->head; s != nullptr; s = s->link) {
        if(s->give->gift_name == input_gift[j]) {
          if(s->give->given) j++;
          else {
            giver = s;
            flag = true;
            break;
          }
        }
      }
      if(flag) break;
    }

    student->get = giver->give;
    giver->give->given = true;

    Mood *mood = find_mood(list_head_node, student->mood_point);
    mood->head = mood->remove(mood, student->name);

    int new_mood;
    if(student->want_name == giver->name) {
      new_mood = student->get->good ? 2 : -2;
    }
    else {
      new_mood = student->get->good ? 1 : -1;
    }

    Mood *to = find_mood(list_head_node, new_mood);
    student->mood_point = new_mood;
    to->head = student->insert(to->head);
  }

  print(list_head_node);

  for(int i = 0; i < len; i++) {
    Student *student = find_student(list_head_node, input_student[i]);
    std::cout << student->name << " " << student->get->gift_name << " ";
    if(student->mood_point == 2) std::cout << ":)))";
    else if(student->mood_point == 1) std::cout << ":)";
    else if(student->mood_point == -1) std::cout << ":(";
    else if(student->mood_point == -2) std::cout << ":(((";
    std::cout << "\n";
  }

  fin.close();

  return 0;
}
