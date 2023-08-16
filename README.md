# Minesweeper Game

This is a simple implementation of the classic Minesweeper game in C++. The game is played on a grid where the player needs to uncover all the cells that do not contain mines without triggering any mine.

![Game](/Images/game.PNG)

## Getting Started

### Prerequisites



- C++ compiler (like g++)

1. Clone the repository:
    ```bash
    https://github.com/jmlopezfabian/Minesweeper-Game.git
    ```

2. Navigate to the cloned directory:

    ```bash
    cd Minesweeper-Game
    ```

3. Compile the code:

    ```bash
     g++ -o build/minesweeper src/Board.cpp src/main.cpp
    ```

4. Run the game:

    ```bash
    ./build/minesweeper
    ```

## How to Play

- The game board consists of cells that are either empty or contain mines.
- Each cell is represented by a symbol:
  - 🔳: Unrevealed cell
  - 🟩: Revealed cell
  - Numeric values indicate the count of neighboring cells containing mines.
  - 🚩: Marks a cell as a potential mine location.

- To reveal a cell, press 1 and then enter the coordinates of the cell (starting with column and then row).
- To mark a cell as a potential mine, press 2 and then enter the coordinates of the cell (starting with column and then row).

- Use the arrow keys to navigate the board and press Enter to perform actions.

- Be careful! Uncovering a cell with a mine ends the game.

## Project Structure

- `src/main.cpp`: Contains the main game loop and user interface.
- `src/Board.cpp`: Implements the game board setup, generation of mines, and cell interactions.
- `include/Board.h`: Defines the Board class.
- `include/PairHash.h`: Provides hash functions for pairs.
- `Images/`: Contains images used in the README.

## Contributing

Contributions are welcome! If you find issues or want to contribute improvements, open a pull request.

## Acknowledgements

This project was inspired by the classic Minesweeper game.