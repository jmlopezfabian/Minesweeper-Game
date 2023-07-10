// Tablero.cpp

#include "../include/Board.h"
#include "../include/PairHash.h"

Board::Board(int rows, int columns, int bombs) : rows(rows), columns(columns), bombs(bombs) {
    // Initialize the board and mines
    board.resize(rows, std::vector<int>(columns,0)); //Initialize all cells with the value 0


    srand(time(NULL));
    std::pair<int,int> position;
    std::unordered_set<std::pair<int, int>, pair_hash> coordinates;
    //Generación aleatoria de las bombas
    for(int i=0;i<bombs; i++){
        do{
            //Random generation of the coordinate x
            position.first = rand() % columns;
            
            //Random generation of the coordinate y
            position.second = rand() % rows;
            
            // Check if position have already been used
            if(coordinates.find(position) == coordinates.end()) {
                // If they have not been used, the bomb is set to the coordinates 
                board[position.first][position.second] = 1;
                coordinates.insert(position);
                break;
            }

        }while(true);
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