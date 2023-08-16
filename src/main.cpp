#include "../include/Board.h"

int main(){
    Board board(12,12);
    board.show();
    std::pair<int,int> first_coordinate;
    
    std::cout<<"Ingresa las corrdenadas (columna)(fila): ";
    std::cin>>first_coordinate.first>>first_coordinate.second;

    //Adjusting the coordinate
    first_coordinate.first -= 1;
    first_coordinate.second -= 1;

    board.generateBombs(20,first_coordinate);
    board.totalBombs = 20;
    board.countBombsNearbyAllCells();
    board.clearAdjacentZeroCells(first_coordinate.second, first_coordinate.first);
    int option;

    do{
        system("clear");
        board.show();
        do{       
            std::cout << "Seleccione una opción: " << std::endl;
            std::cout << "1. Revelar celda" << std::endl;
            std::cout << "2. Poner/Retirar marca de bomba" << std::endl;
            std::cin >> option;

            if (option == 1) {
                std::cout<<"Ingresa las corrdenadas (columna)(fila): ";   
                std::cin>>first_coordinate.first>>first_coordinate.second;
                first_coordinate.first -= 1;
                first_coordinate.second -= 1;

                if(board.hasBomb(first_coordinate.second,first_coordinate.first)){
                    std::cout<<"El juego ha terminado D:"<<std::endl;
                    return 0;
                }
                if(board.revealedCell(first_coordinate.second,first_coordinate.first)){
                    std::cout<<"La celda ingresada ya esta revelada, intenta de nuevo con otra celda.\n";
                }
            } 
            else if (option == 2) {
                std::pair<int,int> mark_coordinate;
                std::cout << "Ingresa las coordenadas (columna)(fila): ";
                std::cin>>mark_coordinate.first>>mark_coordinate.second;
                mark_coordinate.first -= 1;
                mark_coordinate.second -= 1;
                board.toggleBombMark(mark_coordinate.second,mark_coordinate.first);
                break;
            }
        }while(board.revealedCell(first_coordinate.second,first_coordinate.first));
        board.clearAdjacentZeroCells(first_coordinate.second, first_coordinate.first);
    }while(board.checkWinCondition());
}