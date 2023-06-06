#include <iostream>
#include <iomanip>
#include "Grid.h"

int Grid::gridOpenCount = 0;

void Grid::setMine() {
  isMine = true;
}

void Grid::setExplode() {
  isExplode = true;
}

void Grid::setMineCount(int mineCount) {
  this->mineCount = mineCount;
}

void Grid::open() {
  isOpen = true;
  gridOpenCount++;
}

bool Grid::getIsMine() const {
  return isMine;
}

bool Grid::getIsOpen() const {
  return isOpen;
}

int Grid::getMineCount() const {
  return mineCount;
}

int Grid::getGridOpenCount() {
  return gridOpenCount;
}

void Grid::resetGridOpenCount() {
  gridOpenCount = 0;
}

void Grid::render() {
  if (!getIsOpen()) {
    std::wcout << L"\u2B1C";
  } else if(getIsMine()) {
    if (isExplode) {
      std::wcout << L"\U0001F4A5";
    } else {
      std::wcout << L"\U0001F4A3";
    }
  } else if (mineCount == 0) {
    std::cout << "  ";
  } else {
    std::cout << std::setw(2) << mineCount;
  }
}
