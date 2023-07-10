#include "../include/Board.h"

int main(){
    Board board(8,8);
    board.generateBombs(16);
    board.show();
}