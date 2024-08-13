#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
    void bfs(vector<vector<string>>& grid,int row,int col,map<pair<int,int>,bool>&vis){
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[{row,col}]=true;

        while(!q.empty()){
            pair<int,int>fnode=q.front();
            q.pop();
            int x=fnode.first;
            int y=fnode.second;


            //we can move in 4 direction
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                //new cordinates to move up down left and right
                if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && grid[newX][newY]=="1" && !vis[{newX,newY}]){
                    //push only if
                    //new node{newX,newY}->valid index in the grid
                    //grid[newX][newY]='1' island
                    //and is not visited already
                    q.push({newX,newY});
                    //mmark visited
                    vis[{newX,newY}]=true;
                }
            }
        }

    }
    int numIslands(vector<vector<string>>& grid) {
        //each grid is considered as anode if it is 1
        //we need visited to keep track of nodes we have visited
        //node in visited->{i,j}

        
        map<pair<int,int>,bool>vis;//visisted to keep track of nodes already visisted
        int count=0;

        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                //bfs call only if that node is a 1 and is not visited
                if(!vis[{row,col}] && grid[row][col]=="1"){
                    bfs(grid,row,col,vis);
                    count++;
                }
            }
        }
        return count;
    }
int main(){
   // Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of island    s.

    //An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

    vector<vector<string>>grid={
        {"1","1","1","1","0"},
        {"1","1","0","1","0"},
        {"1","1","0","0","0"},
        {"0","0","0","0","0"}
    };
//ans==1    
    cout<<numIslands(grid);
    

}