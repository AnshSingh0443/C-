#include<iostream>
#include<vector>
#include<map>
using namespace std;
    void dfs(int sr,int sc,int oldcolor,int newcolor,vector<vector<int>>&ans,map<pair<int,int>,bool>&vis){
        //mark it visited and fill the color
        vis[{sr,sc}]=true;
        ans[sr][sc]=newcolor;

        //we can move in 4 direction->up(x-1,y),left(x,y-1),down(x+1,y),right(x,y+1)
        for(int i=0;i<4;i++){
            int dx[]={-1,0,1,0};
            int dy[]={0,-1,0,1};
            int newX=sr+dx[i];
            int newY=sc+dy[i];

            if(newX>=0 && newX<ans.size() && newY>=0 && newY<ans[sr].size() && ans[newX][newY]==oldcolor && !vis[{newX,newY}]){
                //newX and newY->valid index
                //ans[newX][newY]=oldcolor=1
                //{newX,newY}->not visited
                dfs(newX,newY,oldcolor,newcolor,ans,vis);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor=image[sr][sc];
        //node->x,y coordinates
        //vis ->to keep track of node already visited
        map<pair<int,int>,bool>vis;
        vector<vector<int>>ans=image;
        //we will make changes in ans array
        //call for dfs(sr,sc)-->starting point

        dfs(sr,sc,oldcolor,color,ans,vis);

        return ans;
        
    }
int main(){
    // Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
    // Output: [[2,2,2],[2,2,0],[2,0,1]]
    // Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), 
    // all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
    // Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel
    vector<vector<int>>image={
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr=1;
    int sc=1;
    int color=2;
    cout<<"Before flood fill:->"<<endl;
    for(auto i:image){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;

    }
    vector<vector<int>>res=floodFill(image,sr,sc,color);
    cout<<"after flood fill:->"<<endl;
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;

    }

}