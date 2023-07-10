// Tablero.cpp

#include "../include/Board.h"


Board::Board(int rows, int columns, int bombs) : rows(rows), columns(columns), bombs(bombs) {
    // Inicializar el tablero y las minas
    board.resize(rows, std::vector<int>(columns,0)); //Inicializamos todas las casillas con el valor 0
    //Normal = 14 x 18 casilllas
    //20 bombas

    srand(time(NULL));
    int x;
    int y;

    std::vector<int> coordinates_x(bombs);
    std::vector<int> coordinates_y(bombs);
    //Generación aleatoria de las bombas
    for(int i=0;i<bombs; i++){
        //Random generation of the coordinate x
        x = rand() % columns;

        //Random generation of the coordinate y
        y = rand() % rows;

        board[x][y] = 1;
    }
}

void Board::show() {
    // Show the current state of the board
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

void Board::clearCell(int fila, int columna) {
    // Clear the cell at the specified row and column
    // ...
}