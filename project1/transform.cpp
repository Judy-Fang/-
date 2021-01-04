#include<iostream>
#include "sudoku.h"
using namespace std;
int main() {
    int map[9][9];
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin>>map[i][j];
        }
    }
    Sudoku Trans;
    Trans.transform(map);
    return 0;
}
