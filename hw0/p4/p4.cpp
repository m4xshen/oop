#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct Team {
  std::string name;
  int point = 0;
  int score = 0;
  bool del = false;
};

Team team[8][4];

int comp(Team team1, Team team2) {
  if(team1.point == team2.point)
    return team1.score > team2.score;

  return team1.point > team2.point;
}

int calcPoint(int point1, int point2) {
  if(point1 > point2) return 3; // win
  else if(point1 < point2) return 0; // lose
  else return 1; // draw
}

void addScore(std::string name, int score1, int score2) {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 4; j++) {
      if(team[i][j].name == name) {
        team[i][j].point += calcPoint(score1, score2);
        team[i][j].score += score1;
      }
    }
  }
}

int stor(std::string s) {
  auto found = s.find('(');
  if(found != std::string::npos) { // found
    std::string news = "";
    found++;

    while(s[found] != ')') {
      news += s[found];
      found++;
    }
    s = news;
  }

  return std::stoi(s);
}

int main(int argc, char **argv) {
  std::ifstream fin(argv[1]);
  std::ofstream fout(argv[2]);
  
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 4; j++)
      fin >> team[i][j].name;

  std::string team1, team2, trash;
  int score1, score2;
  for(int k = 0; k < 48; k++) {
    fin >> team1 >> team2 >> score1 >> trash >> score2;
    addScore(team1, score1, score2);
    addScore(team2, score2, score1);
  }

  for(int i = 0; i < 8; i++) {
    std::sort(team[i], team[i]+4, comp);
  }

  std::vector<int> result;
  std::string s1, s2;
  while(fin >> s1 && s1 != "=") {
    int r1, r2;
    fin >> trash >> s2;
    r1 = stor(s1);
    r2 = stor(s2);
    result.push_back((r1 > r2) ? 0 : 1);
  }

  std::vector<Team> vt;
  int ds; // first draw straw
  bool first = true;
  while(fin >> ds) {
    if(first) first = false;
    else fout << "=\n";

    vt.resize(16);
    vt[ds-1] = team[0][0];
    for(int i = 1; i < 8; i++) {
      fin >> ds;
      vt[ds-1] = team[i][0];
    }
    for(int i = 0; i < 8; i++) {
      fin >> ds;
      vt[ds-1] = team[i][1];
    }

    int t = 0;
    for(int n = 16; n > 1; n /= 2) {
      for(int i = 0; i < n; i += 2) {
        fout << vt[i].name << " v.s. " << vt[i+1].name << "\t";

        if(t < result.size()) {
          fout << "The winner is " << vt[i+result[t]].name << "\n";
          vt[i+(!result[t])].del = true;
          t++;
        }
        else {
          vt[i].del = true;
          vt[i+1].del = true;

          Team tbd;
          tbd.name = "TBD";
          vt.push_back(tbd);
          fout << "The game is comming soon...\n";
        }
      }

      for(auto it = vt.begin(); it != vt.end();) {
        if(it->del) {
          vt.erase(it);
        }
        else it++;
      }
    }
    vt.clear();
  }

  fin.close();
  fout.close();

  return 0;
}
