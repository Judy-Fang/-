#include<iostream>
#include"sudoku.h"
using namespace std;

Sudoku::Sudoku() {};

void Sudoku::printMap(int map[9][9]) {
    for(int row=0; row<9; row++) {
        for(int col=0; col<9; col++) {
            if(col<8) {
                cout<<map[row][col]<<" ";
            } else if(col==8) {
                cout<<map[row][col]<<"\n";
            }
        }
    }
    exit(0);
}

void Sudoku::Answer(int map[9][9],int ans[9][9]) {//store the answer
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            ans[i][j]=map[i][j];
        }
    }
}

void Sudoku::solve(int map[9][9],int grid[9][9],int ans[9][9]) {
    if(Unassigned(map)==false) {//one solution
        Answer(map,ans);
        cout<<"1"<<"\n";
        printMap(ans);
    } else {//no solution
        Answer(map,ans);
    }
    for(int i=0; i<9; i++) {
        for(int j = 0; j< 9; j++) {
            if(map[i][j]== 0) {//fill in number
                for(int num = 1; num<10; num++) {
                    if(isCorrect(i,j,i/3*3+j/3,num,map,grid)) {
                        map[i][j]=num;
                        grid[i/3*3+j/3][(i%3)*3+(j%3)]=num;//record the num in the grid
                        solve(map,grid,ans);
                    }
                    map[i][j] = 0;
                    grid[i/3*3+j/3][(i%3)*3+(j%3)]=0;
                }
                return ;//break
            }
        }
    }
}

void Sudoku::count(int map[9][9],int num[9][9][9]) {//check what number can put in the map
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(map[i][j]!=0) { //record the number already know
                for(int k=0; k<9; k++) {
                    num[i][j][k]=1;//same palce
                    num[k][j][map[i][j]-1]=1;//same col
                    num[i][k][map[i][j]-1]=1;//same row
                }
            }
        }
    }
    //same grid
    int startrow,startcol;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(map[i][j] != 0) {
                startrow=i/3*3;//0,3,6
                startcol=j/3*3;//0,3,6
                for(int row= 0; row<3; row++) {
                    for(int col= 0; col<3; col++) {
                        num[startrow+row][startcol+col][(map[i][j]-1)] = 1;
                    }
                }
            }
        }
    }
}

bool Sudoku::CheckUnique(int map[9][9]) {
    //(已知如果少於17，一定不唯一解)
    int count=0;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(map[i][j]!=0) {
                count++;
            }
        }
    }
    if(count<17) {
        return false;
    }
    return true;
}

bool Sudoku::CheckNo(int ans[9][9]) {
    int no=0;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(ans[i][j]!=0) {
                no++;
            }
        }
    }
    return true;
}


bool Sudoku::Unassigned(int map[9][9]) {
    for(int i= 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(map[i][j] == 0)
                return true;
        }
    }
    return false;
}


bool Sudoku::fillNum(int map[9][9],int num[9][9][9]) {
    int x,y,z,r,s;
    int check_row=1,check_col=1,check_grid=1,one=1;
    //case 1(row,col,only one can fill)
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            for(int k=0; k<9; k++) {
                if(num[k][i][j]==0) {
                    check_row--;
                    x=k;
                }
                if(num[i][k][j]==0) {
                    check_col--;
                    y=k;
                }
                if(num[i][j][k]== 0) {
                    one--;
                    z=k;
                }
            }
            if(check_row==0) {
                map[x][i]=j+1;
                return true;
            }
            if(check_col==0) {
                map[i][y]=j+1;
                return true;
            }
            if(one==0) {
                map[i][j]= z+1;
                return true;
            }
            check_row=1, check_col=1,one=1;
        }
    }
    //case 2(grid)
    int startrow,startcol;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(map[i][j] == 0) {
                startrow=i/3*3;//0,3,6
                startcol=j/3*3;//0,3,6
                for(int k=0; k<9; k++) {
                    for(int row=0; row<3; row++) {
                        for(int col=0; col<3; col++) {
                            if(num[startrow+row][startcol+col][k]==0) {
                                check_grid--;
                                r=startrow+row;
                                s=startcol+col;
                            }
                        }
                    }
                    if(check_grid==0) {
                        map[r][s]=k+1;
                        return true;
                    }
                    check_grid=1;
                }
            }
        }
    }
    return false;
}

bool Sudoku::checkRow(int row,int num,int map[9][9]) {
    for(int j=0; j<9; j++) {
        if (map[row][j]==num)//num already fill in same row
            return false;
    }
    return true;
}

bool Sudoku::checkCol(int col,int num,int map[9][9]) {
    for(int i=0; i<9; i++) {
        if (map[i][col]==num)//num already fill in same col
            return false;
    }
    return true;
}

bool Sudoku::checkGrid(int grid[9][9],int board,int num) {
    for(int j=0; j<9; j++) {
        if (grid[board][j]==num)//num already fill in same row
            return false;
    }
    return true;
}


bool Sudoku::isCorrect(int row,int col,int board,int num,int map[9][9],int grid[9][9]) {
    return checkRow(row,num,map) && checkCol(col,num,map) && checkGrid(grid,board,num);
}






