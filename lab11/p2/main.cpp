#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

bool flag = false;
std::map<std::string, int> ans;
std::vector<std::string> ansv;

void f(std::map<std::string, int> m, std::string str, std::vector<std::string> v) {
  if (str.length() == 0) {
    flag = true;
    ans = m;
    ansv = v;
  }

  for (auto pair : m) {
    if (flag) {
      return;
    }

    if (str.find(pair.first) == 0 && m[pair.first] > 0) {
      std::map<std::string, int> nm = m;
      nm[pair.first]--;

      std::vector<std::string> nv = v;
      nv.push_back(pair.first);
      f(nm, str.substr(pair.first.length()), nv);
    }
  }
}

int main(int argc, char **argv) {
  std::ifstream fin(argv[1]);
  std::map<std::string, int> m;

  std::string word;
  while (fin >> word) {
    int count;
    fin >> count;
    m[word] = count;
  }

  f(m, argv[2], {});

  if (flag) {
    for (auto pair : m) {
      if (pair.second == ans[pair.first]) {
        continue;
      }
      std::cout << pair.first << ": " << pair.second - ans[pair.first] <<
        " (" << pair.second << "->" << ans[pair.first] <<  ")\n";
    }

    std::cout << "True\n";

    for (std::string s : ansv) {
      std::cout << s << " ";
    }
  } else {
    std::cout << "False";
  }
  std::cout << "\n";

  return 0;
}
