#include<iostream>
#include<ctime>
#include"sudoku.h"
using namespace std;

Sudoku::Sudoku() {};

void Sudoku::set(int map[9][9],int a,int b) {
    int s,r;
    for(int count=0; count<3; count++) {
        s=rand()%3+a;
        r=rand()%3+b;
        if(map[s][r]!=0) {
            map[s][r]=0;
        } else if(map[s][r]==0) {
            count--;
        }
    }
};

void Sudoku::generate(int map[9][9]) {
    srand(time(NULL));
    int i,j;
    for(i=0; i<=6; i+=3) {
        for(j=0; j<=6; j+=3) {
            set(map,i,j);
        }
    }

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


