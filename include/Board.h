// Board.h

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <time.h>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <cstdlib>
#include <map>

class Board {
    public:
    Board(int rows, int columns);
    void show();
    void clearCell(int row, int column);
    void generateBombs(int bombs, std::pair<int,int> first_coordinate);
    int countBombsNearby(int row, int column);
    void countBombsNearbyAllCells();
    void clearAdjacentZeroCells(int row, int column);
    bool hasBomb(int row, int column);
    bool checkWinCondition();
    void initializeRemainingCells();
    int totalBombs;
    void revealCell(int row, int column);
    bool revealedCell(int row, int column);
    void toggleBombMark(int row, int column);

    private:
    int rows;
    int columns;
    int remainingCells;

    std::vector<std::vector<char>> board;
    std::vector<std::vector<bool>> visibleCells;
    std::vector<std::vector<bool>> markedCells; //Guard cells that the player suspects are mines
};

#endif