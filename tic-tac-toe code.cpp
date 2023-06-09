#include <iostream>
using namespace std;

// Define the Tic-Tac-Toe board as a 2D array
char** board;

// Define the board size (3x3)
const int boardSize = 3;

// Initialize the board with empty spaces
void initBoard() {
    board = new char*[boardSize];
    for (int i = 0; i < boardSize; i++) {
        board[i] = new char[boardSize];
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the current board state
void displayBoard() {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < boardSize; i++) {
        cout << i+1 << " ";
        for (int j = 0; j < boardSize; j++) {
            cout << board[i][j] << "|";
        }
        cout << endl;
    }
}
// Check if the game is over (win or tie)
bool isGameOver() {
    // Check rows for a win
    for (int i = 0; i < boardSize; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    // Check columns for a win
    for (int j = 0; j < boardSize; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }

    // Check diagonals for a win
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    // Check for a tie
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Check if a move is valid (within bounds and on an empty space)
bool isValidMove(int row, int col) {
    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    return true;
}

// Get a valid move from the player
void getMove(int& row, int& col, char player) {
    do {
        cout << "Player " << player << ", enter row and column (e.g. 1 2): ";
        cin >> row >> col;
        row--; col--; // Convert to 0-based indexing
    } while (!isValidMove(row, col));
}
void playGame() {
    char player = 'X';
    int row, col;
    bool gameOver = false;
initBoard();
displayBoard();

while (!gameOver) {
    getMove(row, col, player);
    board[row][col] = player;
    displayBoard();
    gameOver = isGameOver();
    if (!gameOver) {
        player = (player == 'X') ? 'O' : 'X';
    }
}

// Game is over, declare winner or tie
if (player == 'X') {
    cout << "Player O wins!" << endl;
}
else if (player == 'O') {
    cout << "Player X wins!" << endl;
}
else {
    cout << "Tie game!" << endl;
}

// Deallocate memory for the board
for (int i = 0; i < boardSize; i++) {
    delete[] board[i];
}
delete[] board;
}

int main() {
    playGame();
    return 0;
}
