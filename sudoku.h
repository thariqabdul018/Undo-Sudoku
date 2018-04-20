#include<iostream>
#include<math.h>
#include<cstdlib>

using namespace std;

class sudoku
{
public:
    sudoku();
    void initializeSudokuGrid();
    void printSudokuGrid();
    bool solveSudoku();
    bool findEmptyGridSlot(int &row, int &col);
    bool canPlaceNum(int row, int col, int num);
    bool numAlreadyInRow(int row, int num);
    bool numAlreadyInCol(int col, int num);
    bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num);
    int grid[9][9];
};

sudoku::sudoku()
{
    for (int i = 0; i < 9; i++)    {
        for (int j = 0; j < 9; j++)        {
            grid[i][j] = 0;
        }
    }
    std::cout << "all the grid locations are initialise to zero";
}

void sudoku::initializeSudokuGrid(){
    char x = 'y';
    char y = 'y';
    while (x == 'y')    {
        int row, col, var;
        std::cout
                << "\n enter the row,column and integer in the box(that is 1-9 numbers \n";
        std::cin >> row;
        std::cin >> col;
        std::cin >> var;
        grid[row][col] = var;
        std::cout
                << "\n Want to undo ? (y/n) \n";
        std::cin >> y;
        std::cout
                << "\n Want to enter more ? (y/n) \n";
        std::cin >> x;
    }
    
    while (y == 'y'){
    	int row, col, var;
    	grid[row][col] = 0;
	}
}

void sudoku::printSudokuGrid(){
    std::cout << "\n";
    for (int i = 0; i < 9; i++)    {
        for (int j = 0; j < 9; j++)        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool sudoku::solveSudoku(){
    int row, col;
    if (findEmptyGridSlot(row, col))    {
        for (int num = 1; num <= 9; num++)        {
            if (canPlaceNum(row, col, num))            {
                grid[row][col] = num;
                if (solveSudoku()) //recursive call
                    return true;
                grid[row][col] = 0;
            }
        }
        return false; //backtrack
    }
    else
        return true; //there are no empty slots
}

bool sudoku::numAlreadyInRow(int row, int num){
    for (int i = 0; i < 9; i++)    {
        if (num != 0 && grid[row][i] == num)
            return true;
    }
    return false;
}

bool sudoku::numAlreadyInCol(int col, int num){
    for (int i = 0; i < 9; i++)    {
        if (num != 0 && grid[i][col] == num)
            return true;
    }
    return false;
}

bool sudoku::canPlaceNum(int row, int col, int num){
    if (!numAlreadyInRow(row, num)){
        if (!numAlreadyInCol(col, num)){
            int smallGridRow = row - row % 3;
            int smallGridCol = col - col % 3;
            if (!numAlreadyInBox(smallGridRow, smallGridCol, num)){
                return true;
            }
        }
    }
    return false;
}

bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i + smallGridRow][j + smallGridCol] == num)
                return true;
        }
    }
    return false;
}

bool sudoku::findEmptyGridSlot(int &row, int &col){
    for (row = 0; row < 9; row++){
        for (col = 0; col < 9; col++){
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}
