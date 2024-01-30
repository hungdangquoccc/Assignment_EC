#pragma once
#include <vector>

using namespace std;

class CaroModel {
private:
    int rows;
    int cols;
    vector<vector<char>> board;

public:
    CaroModel(int numRows, int numCols);
    bool markX(int row, int col);
    bool markO(int row, int col);
    char getCell(int row, int col) const;
    bool isBoardFull() const;
    bool checkWin(int row, int col) const;
    void resetBoard();
    int getRows();
    int getCols();
};