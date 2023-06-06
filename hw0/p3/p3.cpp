#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

#define Parent 0
#define Left 1
#define Right 2
#define Cleft 3
#define Cright 4

struct Node {
  Node *nodes[5] = {nullptr};
  Node *prev = nullptr;

  int cost;
  int min_cost = -1;
  int id;
};

int main(int argc, char **argv) {
  std::ifstream fin(argv[1]);

  Node *root;
  std::vector<Node *> prev;
  std::vector<Node *> curr;

  int l = 6; // length of the circle
  int t = 1; // repetition times of current length
  int i = 0;
  bool first = true;
  std::string s;

  int id = 0;
  while(std::getline(fin, s)) {
    std::stringstream ss(s);

    for(int j = 0; j < l; j++) {
      Node *tmp = new Node;
      ss >> tmp->cost;
      tmp->id = id++;
      curr.push_back(tmp);

      if(first) {
        root = tmp;
        first = false;
      }
    }

    for(int k = 0; k < l; k++) {
      curr[k]->nodes[Left] = curr[(k-1+l) % l];
      curr[k]->nodes[Right] = curr[(k+1) % l];

      if(prev.empty()) continue;

      if(prev.size() == l) {
        for(int k = 0; k < l; k++) {
          curr[k]->nodes[Parent] = prev[k];
          curr[k]->nodes[Parent]->nodes[Cleft] = curr[k];
        }
      }
      else {
        for(int k = 0; k < l; k += 2) {
          curr[k]->nodes[Parent] = prev[k/2];
          curr[k]->nodes[Parent]->nodes[Cleft] = curr[k];

          curr[k+1]->nodes[Parent] = prev[k/2];
          curr[k+1]->nodes[Parent]->nodes[Cright] = curr[k+1];
        }
      }
    }

    prev.clear();
    prev = curr;
    curr.clear();

    if(++i >= t) {
      t++;
      i = 0;
      l *= 2;
    }
  }

  std::queue<Node *> q;
  Node *node = root;
  for(int i = 0; i < 6; i++, node = node->nodes[Right]) {
    if(node->cost >= 1) {
      node->min_cost = node->cost;
      q.push(node);
    }
  }

  bool found = false;
  while(!q.empty()) {
    node = q.front();
    q.pop();

    if(node->nodes[Cleft] == nullptr) {
      found = true;
      break;
    }

    for(int i = 0; i < 5; i++) {
      if(node->nodes[i]!=nullptr && node->nodes[i]->cost>=1 && (
          node->nodes[i]->min_cost==-1 ||
          node->min_cost+node->nodes[i]->cost < node->nodes[i]->min_cost)) {
        node->nodes[i]->prev = node;
        node->nodes[i]->min_cost = node->min_cost + node->nodes[i]->cost;
        q.push(node->nodes[i]);
      }
    }
  }

  std::vector<int> ans;
  while(node != nullptr) {
    ans.push_back(node->id);
    node = node->prev;
  }

  if(found) {
    for(auto it = ans.rbegin(); it != ans.rend(); it++) {
      std::cout << *it;
      if(it != std::prev(ans.rend())) {
        std::cout << " -> ";
      }
    }
  }
  else {
    std::cout << "fail";
  }
  std::cout << "\n";

  fin.close();

  return 0;
}
