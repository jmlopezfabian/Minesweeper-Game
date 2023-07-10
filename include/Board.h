// Board.h

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <time.h>
#include <unordered_set>

class Board {
    public:
    Board(int rows, int columns);
    void show();
    void clearCell(int row, int column);
    void generateBombs(int bombs);
    // ...

    private:
    int rows;
    int columns;
    int bombs;
    std::vector<std::vector<int>> board;
    // Other private members...
};

#endif