#ifndef SUDOKU_H
#define SUDOKU_H
#define UNASSIGNED 0
#include<iostream>
#include<ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku {
  public:
    Sudoku();

    // generate
    void set(int map[9][9],int x,int y);
    void generate(int map[9][9]);

    // transform
    void print(int map[9][9]);
    void swapNum(int map[9][9],int x, int y);
    void swapRow(int map[9][9],int x, int y);
    void swapCol(int map[9][9],int x, int y);
    void rotate(int map[9][9],int x);
    void flip(int map[9][9],int x);
    void transform(int map[9][9]);

    // solve
    bool CheckUnique(int map[9][9]);
    bool CheckNo(int ans[9][9]);
    bool Unassigned(int map[9][9]);
    bool fillNum(int map[9][9],int num[9][9][9]);
    bool checkRow(int row,int num,int map[9][9]);
    bool checkCol(int col,int num,int map[9][9]);
    bool checkGrid(int grid[9][9],int board,int num);
    bool isCorrect(int row,int col,int board,int num,int map[9][9],int grid[9][9]);
    void count(int map[9][9],int num[9][9][9]);
    void solve(int map[9][9],int grid[9][9],int ans[9][9]);
    void Answer(int map[9][9],int ans[9][9]);
    void printMap(int map[9][9]);
};

#endif // SUDOKU_H
