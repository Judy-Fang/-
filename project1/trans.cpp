#include<iostream>
#include "sudoku.h"
using namespace std;

Sudoku::Sudoku() {};

void Sudoku::print(int map[9][9]) {
    int i,j;
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            if(j<8) {
                cout<<map[i][j]<<" ";
            } else if(j==8) {
                cout<<map[i][j]<<"\n";
            }
        }
    }
};

void Sudoku::swapNum(int map[9][9],int x, int y) {
    int i,j;
    int swapNum[9][9];
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            if(map[i][j]==x) {
                swapNum[i][j]=y;
            } else if(map[i][j]==y) {
                swapNum[i][j]=x;
            } else {
                swapNum[i][j]=map[i][j];
            }
        }
    }
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            map[i][j]=swapNum[i][j];
        }
    }
};

void Sudoku::swapRow(int map[9][9],int x, int y) {
    int swapRow[9][9]= {0};
    int i,j,count=0;
    if(x!=0) {
        x*=3;
    }
    if(y!=0) {
        y*=3;
    }
    while(count<3) {
        for(i=0; i<=2; i++) {
            for(j=0; j<9; j++) {
                swapRow[x+i][j]=map[y+i][j];
                swapRow[y+i][j]=map[x+i][j];
            }
        }
        count++;
    }
    for(i=x; i<=x+2; i++) {
        for(j=0; j<9; j++) {
            map[i][j]=swapRow[i][j];
        }
    }
    for(i=y; i<=y+2; i++) {
        for(j=0; j<9; j++) {
            map[i][j]=swapRow[i][j];
        }
    }
};

void Sudoku::swapCol(int map[9][9],int x, int y) {
    int swapCol[9][9]= {0};
    int i,j,count=0;
    if(x!=0) {
        x*=3;
    }
    if(y!=0) {
        y*=3;
    }
    while(count<3) {
        for(i=0; i<9; i++) {
            for(j=0; j<=2; j++) {
                swapCol[i][x+j]=map[i][y+j];
                swapCol[i][y+j]=map[i][x+j];
            }
        }
        count++;
    }
    for(i=0; i<9; i++) {
        for(j=x; j<=x+2; j++) {
            map[i][j]=swapCol[i][j];
        }
    }
    for(i=0; i<9; i++) {
        for(j=y; j<=y+2; j++) {
            map[i][j]=swapCol[i][j];
        }
    }
};
void Sudoku::rotate(int map[9][9],int x) {
    int i,j,p=0,n=0;
    //n=0;
    do {
        p=0;
        int rotate[9][9];
        for(i=8; i>=0; i--) {
            for(j=0; j<9; j++) {
                rotate[j][p]=map[i][j];
            }
            p++;
        }
        for(i=0; i<9; i++) {
            for(j=0; j<9; j++) {
                map[i][j]=rotate[i][j];
            }
        }
        n++;
    } while(n<x);
}

void Sudoku::flip(int map[9][9],int x) {
    int i,j;
    int flip[9][9];
    if(x==1) {
        for(i=0; i<9; i++) {
            for(j=0; j<9; j++) {
                flip[i][j]=map[i][8-j];
            }
        }
    } else if(x==0) {
        for(i=0; i<9; i++) {
            for(j=0; j<9; j++) {
                flip[i][j]=map[8-i][j];
            }
        }
    }
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            map[i][j]=flip[i][j];
        }
    }
};

void Sudoku::transform(int map[9][9]) {
    int i,j,a,x,y;
    do {
        cin>>a;
        switch(a) {
        case 1:
            cin>>x>>y;
            swapNum(map,x,y);
            break;
        case 2:
            cin>>x>>y;
            swapRow(map,x,y);
            break;
        case 3:
            cin>>x>>y;
            swapCol(map,x,y);
            break;
        case 4:
            cin>>x;
            rotate(map,x);
            break;
        case 5:
            cin>>x;
            flip(map,x);
            break;
        }
    } while(a!=0);

    print(map);
}
