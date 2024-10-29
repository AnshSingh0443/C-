#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int m;//rows
    int n;//cols
    int DFS(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&dp){
        //direcction we can move in
        //row-1 col+1
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int dx[]={-1,0,1};
        int dy[]={1,1,1};
        int moves=0;
        for(int i=0;i<3;i++){
            //move only if we the next cell we are moving to is strictly greater and not put of bounds
            int newRow=row+dx[i];
            int newCol=col+dy[i];
            //out of bounds check
            if(newRow < m && newRow >=0 && newCol < n && newCol >=0 && grid[newRow][newCol] > grid[row][col] ){
                //strictly greater check
             
                //why 1+dfs as we are taking the next step and then calinng the same fxn for the next cell
                 moves=max(moves,1+DFS(grid,newRow,newCol,dp));
              
               
            }
        }
        dp[row][col]=moves;
        return moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        //we can start from any cell in 1st col
        int result =0;
        for(int row=0;row<m;row++){
            //why col=0 beacuse we can start from 1st col only
            result=max(result,DFS(grid,row,0,dp));
        }
        return result;
        
    }
};

int main(){

}