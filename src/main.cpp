#include "../include/Board.h"

int main(){
    Board board(10,12);
    board.show();
    std::pair<int,int> first_coordinate;
    std::cout<<"Ingresa la coordenada para iniciar el juego: ";
    std::cin>>first_coordinate.first>>first_coordinate.second;
    board.generateBombs(8,first_coordinate);
    board.show();
}