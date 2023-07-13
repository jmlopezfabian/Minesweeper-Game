// Board.h

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <time.h>
#include <unordered_set>
#include <queue>

class Board {
    public:
    Board(int rows, int columns);
    void show();
    void clearCell(int row, int column);
    void generateBombs(int bombs, std::pair<int,int> first_coordinate);
    int countBombsNearby(int row, int column);
    void countBombsNearbyAllCells();
    void clearAdjacentZeroCells(int row, int column);

    private:
    int rows;
    int columns;
    int bombs;
    std::vector<std::vector<char>> board;
    // Other private members...
};

#endif