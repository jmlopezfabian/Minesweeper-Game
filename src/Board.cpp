// Tablero.cpp

#include "../include/Board.h"
#include "../include/PairHash.h"

Board::Board(int rows, int columns) : rows(rows), columns(columns) {
    // Initialize the board and mines
    board.resize(rows, std::vector<char>(columns,'-')); //Initialize all cells with the value -
    visibleCells.resize(rows, std::vector<bool>(columns, false));
    markedCells.resize(rows,std::vector<bool>(columns, false));
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

    int maxNumDigits = 2;
    int cellWidth = maxNumDigits + 1;

    std::cout<<"     ";
    for(int j=0; j<columns; j++){
        if(j+1 >= 10){
            std::cout<<j+1<<"  ";
        }else
            std::cout<<j+1<<"   ";
    }
    std::cout<<"\n\n\n";

    for(int i=0; i<rows; i++){
         std::cout << std::setw(2) << i+1 << "   ";
        for(int j=0; j<columns; j++){
            if(visibleCells[i][j]){
                if(board[i][j] == '0'){
                    std::cout<<"🟩"<<"  ";
                }else{
                    std::cout<<board[i][j]<<"   ";
                }
            }
            else if(markedCells[i][j]){
                std::cout<<"🚩  ";
            }
            else{
                std::cout<<"🔳  ";
            }
        }
        std::cout<<"\n\n";
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
    //Case 6: The coordinate is on the left top corner.
    else if(row == 0 && column == 0){
        for(int i=0; i<=row+1; i++){
            for(int j=0; j<= column + 1; j++){
                if(board[i][j] == 'B'){
                    count++;
                }
            }
        }
    }
    //Case 7: The coordinate is on the rigth top corner.
    else if(row == 0 && column == columns -1){
        for(int i=0; i<= row+1; i++){
            for(int j=column-1;j<= column; j++){
                if(board[i][j] == 'B'){
                    count++;
                }
            }
        }
    }
    //Case 8: The coordinate is on the left bottom corner.
    else if(column == 0 && row == rows -1){
        for(int i=row-1; i<= rows-1; i++){
            for(int j=0; j<= column+1; j++){
                if(board[i][j] == 'B'){
                    count++;
                }
            }
        }
    }
    // Case 9: The coordinate is on the bottom right corner
else if (row == rows - 1 && column == columns - 1) {
    for (int i = row - 1; i <= rows - 1; i++) {
        for (int j = column - 1; j <= column; j++) {
            if (board[i][j] == 'B') {
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
        visibleCells[row][column] = true;
    }
}

void Board::countBombsNearbyAllCells(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns;j++){
            if(board[i][j] != 'B'){
                board[i][j] = Board::countBombsNearby(i,j) + '0';
            }
        }
    }
}

void Board::clearAdjacentZeroCells(int row, int column) {
    std::queue<std::pair<int, int>> queue;
    visibleCells[row][column] = true;
    //board[row][column] = 'X';
    
    queue.push(std::make_pair(row, column));

    while (!queue.empty()) {
        std::pair<int, int> current = queue.front();
        queue.pop();
        int currentRow = current.first;
        int currentColumn = current.second;
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if ((i == 0 && j != 0) || (i != 0 && j == 0)) {
                    int adjacentRow = currentRow + i;
                    int adjacentColumn = currentColumn + j;
                    
                    if (adjacentRow >= 0 && adjacentRow < rows && adjacentColumn >= 0 && adjacentColumn < columns) {
                        if (!visibleCells[adjacentRow][adjacentColumn] && board[adjacentRow][adjacentColumn] != 'B') {
                            visibleCells[adjacentRow][adjacentColumn] = true;
                            if (board[adjacentRow][adjacentColumn] == '0') {
                                queue.push(std::make_pair(adjacentRow, adjacentColumn));
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Board::hasBomb(int row, int column){
    return board[row][column] == 'B';
}

void Board::initializeRemainingCells() {
    int totalCells = rows * columns;
    remainingCells = totalCells - totalBombs;
}

bool Board::checkWinCondition() {
    return remainingCells == 0;
}

void Board::revealCell(int row, int column) {
    if (!visibleCells[row][column]) {
        visibleCells[row][column] = true;
        if (board[row][column] != 'B') {
            remainingCells--;
        }
    }
}

bool Board::revealedCell(int row, int column){
    return visibleCells[row][column];
}

void Board::toggleBombMark(int row, int column){
    markedCells[row][column] = !markedCells[row][column];
}