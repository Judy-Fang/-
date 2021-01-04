#include<iostream>
#include"sudoku.h"
using namespace std;
int main() {
    int i,j,k,no=0;
    bool a,b,c;
    int map[9][9];//question
    int ans[9][9];//answer
    int grid[9][9]= {0};//valid
    int num[9][9][9]= {0};//number to fill
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin>>map[i][j];
        }
    }
    Sudoku Sol;
    a=Sol.CheckUnique(map);
    //multiple solution
    if(a==false) {
        cout<<"2"<<endl;
        exit(0);
    }

    //one solution
    do {
        Sol.count(map,num);
        b=Sol.fillNum(map,num);//fill in number until all map
        if(b==false)
            break;
    } while(true);

    for(i= 0; i< 9; i++)
        for(j = 0; j < 9 ; j++) {
            grid[i/3*3+j/3][(i%3)*3+(j%3)]=map[i][j];
        }
    Sol.solve(map,grid,ans);//one solition print out

    //no solution
    c=Sol.CheckNo(ans);
    if(c==true) {
        cout<<"0"<<endl;
    }

    return 0;
}

