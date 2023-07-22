#include "../include/Board.h"

int main(){
    Board board(12,12);
    board.show();
    std::pair<int,int> first_coordinate;
    
    std::cout<<"Enter the coordinate to start the game: ";
    std::cin>>first_coordinate.first>>first_coordinate.second;

    //Adjusting the coordinate
    first_coordinate.first -= 1;
    first_coordinate.second -= 1;

    board.generateBombs(20,first_coordinate);
    board.totalBombs = 20;
    board.countBombsNearbyAllCells();
    board.clearAdjacentZeroCells(first_coordinate.second, first_coordinate.first);
    board.show();

    do{
        std::cin>>first_coordinate.first>>first_coordinate.second;
        //Adjusting the coordinate
        first_coordinate.first -= 1;
        first_coordinate.second -= 1;
        if(board.hasBomb(first_coordinate.second,first_coordinate.first)){
            std::cout<<"El juego se ha terminado :c";
            break;
        }
        board.clearAdjacentZeroCells(first_coordinate.second, first_coordinate.first);
        board.show();
    }while(!board.checkWinCondition());
}