#include<iostream>
#include<vector>
#include<queue>

using namespace std;
    int minimumEffortPath(vector<vector<int>>& heights) {
        //using min heapp to store pair of maxdiff between nodes along the path and coordinates x and y
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        //effort/  diff is upadated as we go along diffrent paths we use diff 2d array to store the min diff found
        //using diff matrix to store min effort to reach that node
        //eg diff[x][y]=z-->z is the min effort to reach node/coordinate x ,y
        vector<vector<int>>diff (heights.size(),vector<int>(heights[0].size(),INT_MAX));

        //initially push 0,0->src or starting point 
        pq.push({0,{0,0}});
        diff[0][0]=0;

        //process till pq is not empty->ends when empty ot ans found
        while(!pq.empty()){
            auto fnode=pq.top();
            int fdiff=fnode.first;
            int x=fnode.second.first;
            int y=fnode.second.second;
            pq.pop();

            //chech if we reached destination
            if(x==heights.size()-1 && y==heights[x].size()-1){
                return diff[x][y];
            }
            //move in 4 direction
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                //check if the new cordinate are a valid  index
                if(newX >=0 && newX <heights.size() && newY>=0 && newY<heights[newX].size()){
                    //diffrece
                    int currDiff=abs(heights[x][y]-heights[newX][newY]);
                    //save effort->maximum absolute difference in heights between two consecutive cells of the route.. 
                    int newMax=max(fdiff,currDiff);
                    //update diff/effort if it is less than already exisiting effort
                    if(newMax < diff[newX][newY]){
                        diff[newX][newY]=newMax;
                        //push to pq
                        pq.push({newMax,{newX,newY}});
                    }
                }
            }
        }

        return 0;


        
    }

int  main(){
        // You are a hiker preparing for an upcoming hike.
        // You are given heights, a 2D array of size rows x columns,
        // where heights[row][col] represents the height of cell (row, col). 
        // You are situated in the top-left cell, (0, 0), 
        // and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed).
        // You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

        // A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

        // Return the minimum effort required to travel from the top-left cell to the bottom-right cell.


        // Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
        // Output: 1
        // Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, 
        //which is better than route [1,3,5,3,5].

        vector<vector<int>>heights={
            {1,2,3},
            {3,8,4},
            {5,3,5}
        };
        cout<<minimumEffortPath(heights);

}