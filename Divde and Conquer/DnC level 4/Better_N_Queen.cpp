#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// we will use unorderd map in issafe fn to reduce T.c
unordered_map<int,bool>rowCheck;
unordered_map<int,bool>upperLeftDiagonalCheck;
unordered_map<int,bool>lowerLeftDiagonalCheck;

bool isSafe(int row,int col,vector<vector<char>>&board,int n){
    // if queen is present in the  row
    if(rowCheck[row]==true){
        return false;
    }
    // if queen is present in the uppper left diagonal direction->pattern(n-1+col-row ) 
    if(upperLeftDiagonalCheck[n-1+col-row]==true){
        return false;
    }

    //if queen is prsent in the lower diagonal direction->(pattern(row+col)) 
    if(lowerLeftDiagonalCheck[row+col]==true){
        return false;
    }

    return true;
}
void printSoultion(vector<vector<char>>&board,int n){
    for(int i=0;i<n;i++){
        for (int j = 0; j < n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve(vector<vector<char>>& board,int col,int n){
    //base case->we have found the soln last queen is placed 
    if(col>=n){
        printSoultion(board,n);
        return;
    }

    //solve one case->place the one queen rest->recursion
    // trying all rows  at each col for one queen
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            // if it is safe to place wueen at board[row][col]->place the queen
            board[row][col]='Q';
            // update the map
            rowCheck[row]=true;
            upperLeftDiagonalCheck[n-1+col-row]=true;
            lowerLeftDiagonalCheck[row+col]=true;

            // now next col for next queen
            solve(board,col+1,n);

            //backtracking->to ttry new soln we undo the change made
            board[row][col]='-';
            rowCheck[row]=false;
            upperLeftDiagonalCheck[n-1+col-row]=false;
            lowerLeftDiagonalCheck[row+col]=false;
        }
    }
}
int main(){
    //Problem statement 
    // n queens are need to be placed in a sqaure matrix such that no queen can kill each other
    // or each row should have a queen
    // every colum shoud have a queen and no queen attack each other

    // A queen can travel in row, column and diagonal so no other queen should been in such a pos

    int n=4;
    vector<vector<char>>board(n,vector<char>(n,'-'));// a matrix of nxn is created which is intitialized to '-'
    printSoultion(board,n);
    int col=0;//we will be placing queen col wise->0 to n-1
    solve(board,col,n);
    
}