#include "model.h"

int CaroModel::getRows()
{
    return rows;
}

int CaroModel::getCols()
{
    return cols;
}

CaroModel::CaroModel(int numRows, int numCols)
    : rows(numRows), cols(numCols) {
    // Initialize the board
    board.resize(rows, std::vector<char>(cols, ' '));
}

bool CaroModel::markX(int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = 'X';
        return true;
    }
    return false;
}

bool CaroModel::markO(int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = 'O';
        return true;
    }
    return false;
}

char CaroModel::getCell(int row, int col) const {
    return board[row][col];
}

bool CaroModel::isBoardFull() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool CaroModel::checkWin(int row, int col) const {
    char currentPlayer = board[row][col];

    // Check horizontally
    int count = 0;
    for (int i = 0; i < cols; ++i) {
        if (board[row][i] == currentPlayer) {
            count++;
            if (count >= 3) {
                return true;  // Win condition met horizontally
            }
        } else {
            count = 0;
        }
    }

    // Check vertically
    count = 0;
    for (int i = 0; i < rows; ++i) {
        if (board[i][col] == currentPlayer) {
            count++;
            if (count >= 3) {
                return true;  // Win condition met vertically
            }
        } else {
            count = 0;
        }
    }

    // Check diagonally (from top-left to bottom-right)
    count = 0;
    for (int i = -4; i <= 4; ++i) {
        int r = row + i;
        int c = col + i;
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            if (board[r][c] == currentPlayer) {
                count++;
                if (count >= 3) {
                    return true;  // Win condition met diagonally
                }
            } else {
                count = 0;
            }
        }
    }

    // Check diagonally (from top-right to bottom-left)
    count = 0;
    for (int i = -4; i <= 4; ++i) {
        int r = row - i;
        int c = col + i;
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            if (board[r][c] == currentPlayer) {
                count++;
                if (count >= 3) {
                    return true;  // Win condition met diagonally
                }
            } else {
                count = 0;
            }
        }
    }

    return false;  // No win condition met
}


void CaroModel::resetBoard() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = ' ';
        }
    }
}
