#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<vector<string>> res;

bool canPlaceQueen(int row,int col,int n){
    
    //col..
    for(int i=row-1;i>=0;i--){
        if(grid[row][col]=='Q') return false;
    }
    //left-diagonal
    for(int i=row-1,j=col-1;i>=0,j>=0;i--,j--)
    {
        if(grid[i][j]=='Q') return false;
    }
    //right diagonal
    for(int i=row-1,j=col+1;i>=0,j<n;i--,j++){
        if(grid[i][j]=='Q') return false;
    }
    return true;
}

void f(int row,int n){

    if(row==n){
        string str="";
        vector<string> asd;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) str+=grid[i][j];
            asd.push_back(str);
        }
        res.push_back(asd);
    }
    

    for(int col=0;col<n;col++){
        if(canPlaceQueen(row,col,n)){
            grid[row][col]='Q';
            f(row+1,n);
            grid[row][col]='.';
        }
    }
}



vector<vector<string>> nqueen(int n){
    grid.resize(n,vector<char> (n,'.'));
    f(0,n);
}


int main(){

}