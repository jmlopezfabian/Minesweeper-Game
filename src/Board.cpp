// Tablero.cpp

#include "../include/Board.h"
#include "../include/PairHash.h"

Board::Board(int rows, int columns) : rows(rows), columns(columns) {
    // Initialize the board and mines
    board.resize(rows, std::vector<char>(columns,'-')); //Initialize all cells with the value -
}

void Board::generateBombs(int bombs, std::pair<int,int> first_coordinate) {
    /*
    The function takes the number of bombs as a parameter and uses a loop to 
    generate unique random positions for each bomb. It utilizes the PairHash 
    structure, which provides a custom hash function for coordinate pairs, 
    to ensure that duplicate positions are avoided. 
    */

    srand(time(NULL));
    std::pair<int,int> position;
    std::unordered_set<std::pair<int, int>, pair_hash> coordinates;
    coordinates.insert(first_coordinate);
    //Generación aleatoria de las bombas
    for(int i=0;i<bombs; i++){
        do{
            //Random generation of the coordinate x
            position.first = rand() % (columns);
            
            //Random generation of the coordinate y
            position.second = rand() % (rows);
            
            // Check if position have already been used
            if(coordinates.find(position) == coordinates.end()) {
                // If they have not been used, the bomb is set to the coordinates 
                //[row][column] = [y][x]
                board[position.second][position.first] = 'B';
                coordinates.insert(position);
                break;
            }

        }while(true);
    }
}

void Board::show() {
    // Show the current state of the board
    std::cout<<"\n";
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

int Board::countBombsNearby(int row, int column){
    //Count the bombs close to a coordinate 
    int count = 0;

    //Case 1: The coordinate is not on the edge of the board (previously implemented). 
    if (row >= 1 && row < rows-1 && column >= 1 && column < columns -1){ 
        for(int i = row-1; i<= row+1; i++){
            for(int j = column-1; j<= column+1; j++){
                if(board[i][j] == 'B'){
                    count ++;
                } 
            }
        }    
    }
    //Case 2: The coordinate is on the left edge of the board but not at the corners.
    else if(column == 0 && row >= 1 && row < rows -1){
        for(int i = row-1; i<= row+1; i++){
            for(int j = 0; j<= column+1; j++){
                if(board[i][j] == 'B'){
                    count++;
                }
            }
        }
    }
    //Case 3: The coordinate is on the rigth edge of the board but not at the corners.
    else if(column == columns-1 && row >= 1 && row < rows -1){
        for(int i = row-1; i<= row+1; i++){
            for(int j=column-1; j <= columns -1; j++){
                if(board[i][j] == 'B'){
                    count++;
                }
            }
        }
    }
    //Case 4: The coordinate is on the top edge of the board but not at the corners.
    else if(row == 0 && column >= 1 && column < columns -1){
        for(int i= 0; i<= row+1; i++){
            for(int j=column-1; j<= column+1; j++){
                if(board[i][j] == 'B'){
                    count++;
                }
            }
        }
    }

    //Case 5: The coordinate is on the bottom edge of the board but not at the corners.
    else if(row == rows-1 && column >= 1 && column < columns -1){
        for(int i=row-1; i<=rows-1; i++){
            for(int j=column-1; j<= column+1; j++){
                if(board[i][j] == 'B'){
                    count++;
                }
            }
        }
    }
    return count;
}

void Board::clearCell(int row, int column) {
    // Clear the cell at the specified row and column
    if(row >= 0 && row < rows && column >= 0 && column < columns){
        board[row][column] = countBombsNearby(row, column) + '0';
    }
}