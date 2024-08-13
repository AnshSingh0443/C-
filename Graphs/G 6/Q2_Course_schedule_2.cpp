#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<queue>
#include<list>

using namespace std;

unordered_map<int,vector<int>>adjList;
        void topoSort(int n,vector<int>&ans){
            queue<int>q;
            unordered_map<int,int>indegree;
            // Calculate indegree
            for(auto i : adjList){
                int src = i.first;
                for(auto nbr : i.second){
                    indegree[nbr]++;
                    
                }
            }
            
            // Put nodes in queue having indegree = 0;
            for(int i = 0;i<n;i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
            // BFS logic
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                ans.push_back(frontNode);
                for(auto nbr : adjList[frontNode]){
                    // As nodes are removed from graph
                    indegree[nbr]--;
                    // check for 0 indegree again
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }
        }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //detect a cycle in graph
        //using topological sort
        //first lets make a graph(adjlist) using prereq
       
        for(auto task:prerequisites){
           int u=task[0];
           int v=task[1];
           //edge task 1 is complete before 0 ie  1----0 v----u
           adjList[v].push_back(u);
        }
        //we have created a map of all courses acc to list->which one to do first (edges)
        //if this graph has a cyle->imposstibe condition->eg  1-0 abd 0-1-->return empty array
        //else retuen topological sort
        vector<int>ans;

        topoSort(numCourses,ans);
        if(ans.size()==numCourses){
            return ans;
        }
        return {};

        
    }

int main(){

    // Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
    // Output: [0,2,1,3]
    // Explanation: There are a total of 4 courses to take.
    // To take course 3 you should have finished both courses 1 and 2.
    // Both courses 1 and 2 should be taken after you finished course 0.
    // So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
    int numCourses=4;
    vector<vector<int>>prerequisites={
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    // bool res=canFinish(numCourses,prerequisites);

    // if(res){
    //     cout<<"true";
    // }else{
    //     cout<<"false";
    // }

    vector<int>res=findOrder(numCourses,prerequisites);
    cout<<"course order:->";
    for(auto i: res){
        cout<<i<<" ";
    }
    

}