#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int size;

class Puzzle {
public:
  Puzzle(int l, int t, int r, int d) {
    joints[0] = l;
    joints[1] = t;
    joints[2] = r;
    joints[3] = d;
  }

  void rotate(int times) {
    while(times--) {
      // rotate joints
      int tmp = joints[3];
      for(int i = 3; i >= 0; i--) {
        joints[i] = joints[i-1];
      }
      joints[0] = tmp;

      // rotate image
      for(int i = 0; i < size/2; i++) {
        for(int j = i; j < size-i-1; j++) {
          int tmp = image[i][j];
          image[i][j] = image[size-1-j][i];
          image[size-1-j][i] = image[size-1-i][size-1-j];
          image[size-1-i][size-1-j] = image[j][size-1-i];
          image[j][size-1-i] = tmp;
        }
      }
    }
  }

  int joints[4];
  char image[100][100];
};

std::vector<Puzzle> vp;

auto findNbr(std::vector<Puzzle>::iterator node, int dir) {
  auto it = vp.begin();
  for(; it != vp.end(); it++) {
    for(int i = 0; i < 4; i++) {
      if(it->joints[i] + node->joints[dir] == 0) {
        it->rotate(((dir+2)%4 -i+4) % 4);

        return it;
      }
    }
  }

  return it;
}

int main(int argc, char **argv) {
  std::ifstream fin(argv[1]);
  std::ofstream fout(argv[2]);

  fin >> size;

  int l, t, r, d;
  char trash;
  std::string s;

  fin.ignore();
  while(getline(fin, s)) {
    std::stringstream ss(s);
    ss >> l >> t >> r >> d;

    Puzzle tmp(l, t, r, d);

    int k = s.find('"') + 1;

    for(int i = 0; i < size; i++)
      for(int j = 0; j < size; j++) {
        tmp.image[i][j] = s[k++];
      }

    vp.push_back(tmp);
  }

  auto origin = vp.begin();

  while(origin->joints[0] != 0) {
    origin = findNbr(origin, 0);
  }
  while(origin->joints[1] != 0) {
    origin = findNbr(origin, 1);
  }

  auto node = origin;

  while(1) {
    for(int i = 0; i < size; i++) {
      while(1) {
        for(int j = 0; j < size; j++) {
          fout << node->image[i][j];
        }
        if(node->joints[2] == 0) break;
        node = findNbr(node, 2);
      }

      fout << "\n";
      node = origin;
    }
    if(node->joints[3] == 0) break;
    origin = findNbr(origin, 3);
    node = origin;
  }

  fin.close();
  fout.close();

  return 0;
}
