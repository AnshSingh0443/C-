#include<iostream>
#include<vector>
using namespace std;
//T.C-o(n!)

bool isSafe(int row,int col,vector<vector<char>>&board,int n){
    // chechking if we can place the queen at currn row,col
    int i=row;
    int j=col;

    //since queen can move in row and diagonals we check those 
    // we dont chech for the col becuz only one queen can be place at a col so no need

    //Row check
    while(j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        j--;
    }
    
    i=row;
    j=col;

    //Upper left Diagonal check
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }

    i=row;
    j=col;

    // lower left diagonal check
    while(i<n&&j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;
    }

    //now since queen can be placed
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
            // now next col for next queen
            solve(board,col+1,n);

            //backtracking->to ttry new soln we undo the change made
            board[row][col]='-';
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