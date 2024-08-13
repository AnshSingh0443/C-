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
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //detect a cycle in graph
        //using topological sort
        //first lets make a graph(adjlist) using prereq
       
        for(int i=0;i<prerequisites.size();i++){
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        //we have created a map of all courses acc to list->which one to do first (edges)
        //if this graph has a cyle->imposstibe condition->eg  1-0 abd 0-1-->return false
        //else retrun true
        vector<int>ans;

        topoSort(numCourses,ans);
        if(ans.size()==numCourses){
            return true;
        }
        return false;

    }

int main(){

    // Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    // Output: false
    // Explanation: There are a total of 2 courses to take. 
    // To take course 1 you should have finished course 0, 
    // and to take course 0 you should also have finished course 1. So it is impossible.
    int numCourses=2;
    vector<vector<int>>prerequisites={
        {0,1},
        {1,0}
    };

    bool res=canFinish(numCourses,prerequisites);

    if(res){
        cout<<"true";
    }else{
        cout<<"false";
    }
    

}