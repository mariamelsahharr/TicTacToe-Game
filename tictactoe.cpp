#include <iostream>
#include <vector>
#include <stdexcept>

// tictac class
class TicTac {
private:
    std::vector<std::vector<char>> board;  // The game board
    char currentPlayer;  // The current player ('X' or 'O')

public:
    // Constructor
    TicTac() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    // Print the game board
    void printBoard() {
        std::cout << "  1 2 3\n"; //prints out column
        for (int i = 0; i < 3; i++) {
            std::cout << i + 1 << " "; // prints out row
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Make a move
    void makeMove(int row, int col) {
        if (row > 0 && row <= 3 && col > 0 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;
        } else {
            throw std::invalid_argument("Invalid move");
        }
    }

    // Check if the current player has won
    bool checkWin() {
        // Check rows
        for (int i = 0; i < 3; i++)
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;

        // Check columns
        for (int i = 0; i < 3; i++)
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    // Switch the current player
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Get the current player
    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

// Main function
int main() {
    TicTac game;  // Create a new game
    int row, col;

    while (true) {
        game.printBoard();  // Print the game board
        std::cout << "Player " << game.getCurrentPlayer() << "enter your move, on seperate lines (row and column): ";
        std::cin >> row >> col;

        try {
            game.makeMove(row, col);  // Make a move
            if (game.checkWin()) {  // Check if the current player has won
                std::cout << "Player " << game.getCurrentPlayer() << " wins!\n";
                break;
            }
            game.switchPlayer();  // Switch the current player
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << ". Try again.\n";
        }
    }

    return 0;
}