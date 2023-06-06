#include <iostream>

#ifndef _GRID_H_
#define _GRID_H_
#include "Grid.h"
#endif

#define cout wcout

using namespace std;

class MineSweeper {
  int sizeX;
  int sizeY;
  int mineNum;

  bool explode;
  bool win;

  Grid** map = nullptr;

public:
  void run();

private:
  // Prepare new grid map
  void newGame();
  void createNewMap();
  void generateMines() {
    for (int i = 0; i < mineNum; i++) {
      int posY, posX;
      do {
        posY = rand() % sizeY;
        posX = rand() % sizeX;
      } while (map[posY][posX].getIsMine());
      map[posY][posX].setMine();
    }
  }
  void countMine();

  // In game interaction
  void openGrid(int pressedPosY, int pressedPosX);
  void propagateWhiteSpace(int pressedPosY, int pressedPosX);

  // After game setting
  void revealAllMines();
  void explodeAllMines();

  // Helper functions
  void checkWin();
  bool isPosValid(int posY, int posX);

  // Render
  void render();
  void renderAnswer() {
    for (int i = 0; i < sizeY; i++) {
      for (int j = 0; j < sizeX; j++) {
        if (map[i][j].getIsMine()) {
          cout << L"\U0001F4A3";
        } else {
          cout << " " << map[i][j].getMineCount();
        }
      }
      cout << endl;
    }
  }
};
