#include "MineSweeper.h"
#include <iomanip>

bool MineSweeper::isPosValid(int posY, int posX) {
  return posX>=0 && posX<sizeX && posY>=0 && posY<sizeY;
}

void MineSweeper::run() {
  while (true) {
    newGame();
    render();
    while (!win && !explode) { // game loop
      int x, y;
      while (true) {
        std::cout << "Please enter the coordinate (x, y) you want to press: ";
        std::cin >> x >> y;
        if (!isPosValid(y, x)) {
          std::cout << "Invalid coordinate!\n";
          continue;
        }

        if (map[y][x].getIsOpen()) {
          std::cout << "Grid (" << x << ", " << y << ") is already pressed!\n";
          continue;
        }

        break;
      }
      openGrid(y, x);
      render();
      countMine();
      checkWin();
    }

    win ? revealAllMines() : explodeAllMines();
    render();
    std::cout << (win ? "You win!\n" : "Mine explode! You lose!\n");

    char op;
    std::cout << "Do you want to play another round?(y/n) ";
    std::cin >> op;
    if (op == 'n') break;
  }
}

void MineSweeper::newGame() {
  Grid::resetGridOpenCount();
  explode = false;
  win = false;

  while (true) {
    std::cout << "Please input map width: ";
    std::cin >> sizeX;
    std::cout << "Please input map height: ";
    std::cin >> sizeY;
    if(sizeX>0 && sizeY>0) break;
    std::cout << "Input Error!\n";
  }
  createNewMap();

  while (true) {
    std::cout << "Please input number of mines: ";
    std::cin >> mineNum;
    if (mineNum>0 && mineNum<=sizeX*sizeY) break;
    std::cout << "Input Error!\n";
  }
  generateMines();

  countMine();
}

void MineSweeper::createNewMap() {
  delete[] map;
  map = new Grid*[sizeY];
  for (int i = 0; i < sizeY; i++)
    map[i] = new Grid[sizeX];
}

void MineSweeper::countMine() {
  for (int i = 0; i < sizeY; i++) {
    for (int j = 0; j < sizeX; j++) {
      int c = 0;
      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          if (k==0 && l==0) continue;
          if (isPosValid(i+k, j+l) && map[i+k][j+l].getIsMine()) c++;
        }
      }
      map[i][j].setMineCount(c);
    }
  }
}

void MineSweeper::openGrid(int pressedPosY, int pressedPosX) {
  if (map[pressedPosY][pressedPosX].getIsMine()) {
    explode = true;
    return;
  }

  propagateWhiteSpace(pressedPosY, pressedPosX);
}

void MineSweeper::propagateWhiteSpace(int pressedPosY, int pressedPosX) {
  if (!isPosValid(pressedPosY, pressedPosX)) return;

  Grid &curr = map[pressedPosY][pressedPosX];
  if (curr.getIsOpen()) return;
  curr.open();
  if (curr.getIsMine() || curr.getMineCount() != 0) return;

  propagateWhiteSpace(pressedPosY+1, pressedPosX);
  propagateWhiteSpace(pressedPosY, pressedPosX+1);
  propagateWhiteSpace(pressedPosY-1, pressedPosX);
  propagateWhiteSpace(pressedPosY, pressedPosX-1);
}

void MineSweeper::render() {
  std::cout << "   ";
  for (int i = 0; i < sizeX; i++)
    std::cout << std::setw(2) << i;
  std::cout << "\n";

  // horizontal line
  std::cout << "  ";
  for (int i = 0; i < sizeX+1; i++)
    std::cout << "--";
  std::cout << "\n";

  for (int i = 0; i < sizeY; i++) {
    std::cout << std::setw(2) << i << "|";
    for (int j = 0; j < sizeX; j++)
      map[i][j].render();
    std::cout << "|\n";
  }

  // horizontal line
  std::cout << "  ";
  for (int i = 0; i < sizeX+1; i++)
    std::cout << "--";
  std::cout << "\n";
}

void MineSweeper::checkWin() {
  if (sizeX*sizeY - Grid::getGridOpenCount() == mineNum) {
    win = true;
  }
}

void MineSweeper::revealAllMines() {
  for (int i = 0; i < sizeY; i++)
    for (int j = 0; j < sizeX; j++)
      if (!map[i][j].getIsOpen())
        map[i][j].open();
}

void MineSweeper::explodeAllMines() {
  revealAllMines();
  for (int i = 0; i < sizeY; i++)
    for (int j = 0; j < sizeX; j++)
      if (map[i][j].getIsMine())
        map[i][j].setExplode();
}
