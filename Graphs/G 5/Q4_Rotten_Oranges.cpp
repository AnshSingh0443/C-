#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

    int orangesRotting(vector<vector<int>>& grid) {
        //we need a queue to store all rotten oranges->coordinate(x,y) and time which is update every new level order ie when adding nbrs
        queue<pair<pair<int,int>,int>>q;
        int anstime=0;//->updated when nbr are added

        vector<vector<int>>ans=grid;

        //step 1:add all rotten oranges to the queue
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                if(grid[row][col]==2){
                    //rotten orange
                    q.push({{row,col},0});
                    //initally->0th miniute->time->0
                }
            }
        }

        //step 2
        while(!q.empty()){
            auto fnode=q.front();
            q.pop();
            int x=fnode.first.first;
            int y=fnode.first.second;
            int time=fnode.second;
            

            //move 4 direction if fresh orange
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX >= 0 && newX < ans.size() && newY >=0 && newY < ans[0].size() && ans[newX][newY] == 1){
                    //valid indexx
                    //fresh orange found
                    //update time-->inserting new time
                    anstime=max(anstime,time+1);
                    q.push({{newX,newY},time+1});
                    //mark as rotten
                    ans[newX][newY]=2;
                }

                
            }
        }

        //handling case when a fresh ornage still remains->return -1
        for(auto i:ans){
            for(auto j:i){
                if(j==1){
                    anstime=-1;
                }
            }
        }

        return anstime;


    }

int main(){
    // You are given an m x n grid where each cell can have one of three values:

    // 0 representing an empty cell,
    // 1 representing a fresh orange, or
    // 2 representing a rotten orange.
    // Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

    // Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

    // Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
    // Output: -1
    // Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

    vector<vector<int>>grid={
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };

    cout<<orangesRotting(grid);

}