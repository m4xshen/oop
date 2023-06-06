#include <string>
#include <vector>

struct item {
  int id;
  std::string name;
  int price;
};

class VM {
private:
  std::vector<item> item_vec;
  std::string password;
  void add_item();
  void remove_item();
  void find_change(int);
  void purchase_item();
  void print_itemList();
  void print_optionList();
  std::string set_password();
public:
  void start();
};
