#include "../include/Board.h"

int main(){
    Board board(10,12);
    board.show();
    board.generateBombs(8);
    board.show();
}