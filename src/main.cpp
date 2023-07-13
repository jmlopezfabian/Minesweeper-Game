#include "../include/Board.h"

int main(){
    Board board(12,12);
    std::pair<int,int> first_coordinate;
    std::cout<<"Ingresa la coordenada para iniciar el juego: ";
    std::cin>>first_coordinate.first>>first_coordinate.second;
    
    //Ajuste de coordenadas
    first_coordinate.first -= 1;
    first_coordinate.second = abs(first_coordinate.second - 12);
    
    board.generateBombs(20,first_coordinate);
    board.countBombsNearbyAllCells();
    //board.clearCell(first_coordinate.second,first_coordinate.first);
    board.clearAdjacentZeroCells(first_coordinate.second, first_coordinate.first);
    board.show();
}