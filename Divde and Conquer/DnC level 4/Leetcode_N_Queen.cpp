#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// we will use unorderd map in issafe fn to reduce T.c
    unordered_map<int,bool>rowCheck;
    unordered_map<int,bool>upperLeftDiagonalCheck;
    unordered_map<int,bool>lowerLeftDiagonalCheck;

    void storeSoultion(vector<vector<char>>&board,int n,vector<vector<string>>&ans){
        vector<string>temp;
        for(int i=0;i<n;i++){
            string output="";
            for (int j = 0; j < n;j++){
                output.push_back(board[i][j]);
            }
            // a soln is stored in a string now store it in temp  (array of string) then in ans
            temp.push_back(output);
        }
       //finally store it in ans
       ans.push_back(temp);
    }

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

    void solve(vector<vector<char>>& board,int col,int n,vector<vector<string>>&ans){
    //base case->we have found the soln last queen is placed 
        if(col>=n){
            storeSoultion(board,n,ans);
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
                solve(board,col+1,n,ans);

                //backtracking->to ttry new soln we undo the change made
                board[row][col]='.';
                rowCheck[row]=false;
                upperLeftDiagonalCheck[n-1+col-row]=false;
                lowerLeftDiagonalCheck[row+col]=false;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        vector<vector<char>>board(n,vector<char>(n,'.'));// a matrix of nxn 
        vector<vector<string>>ans;
        int col=0;//we will be placing queen col wise->0 to n-1
        solve(board,col,n,ans);

        return ans;
    
        
    }

int main(){
    int n=4;
    vector<vector<string>>result=solveNQueens(n);

    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[0].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;

    }



    

}
