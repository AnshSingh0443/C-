#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>>adjList;
    void addEdge(int u,int v,bool direction){
        // direction = 1 -> undirected
        // direction = 0 -> directed
        adjList[u].push_back(v);
        if(direction == 1){
            adjList[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i : adjList){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"("<<j<<","<<j<<"), ";
            }
            cout<<endl;
        }
    }
    void Topological_Sort(int src, stack<int>& s, unordered_map<int,bool>& vis) {
		vis[src]=true;

        for(auto nbr:adjList[src]){
            if(!vis[nbr]){
                Topological_Sort(nbr,s,vis);
            }
        }
        s.push(src);
        
	}
    void dfs(int src, unordered_map<int,bool>& visited, unordered_map<int,list<int> >& adjNew) {
		visited[src] = true;
		cout << src << ", ";

		for(auto nbr: adjNew[src]) {
			if(!visited[nbr] ) {
				dfs(nbr, visited, adjNew);
			}
		} 
	}
	
	int countSCC(int n) {
		stack<int> s;
		unordered_map<int,bool> visited;

		//find topo ordering
		for(int i=0;i<n;i++){
            if(!visited[i]){
                Topological_Sort(i,s,visited);
            }
        }

		//reverse all edges
		unordered_map<int,list<int>>adjNew;
        for(auto t:adjList){
            for(auto nbr:t.second){
                int u=t.first;
                int v=nbr;
                //v--u
                adjNew[v].push_back(u);
            }
        }

		//traversse using DFS--according to topological ordering
		unordered_map<int,bool>visited2;
        int count=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(!visited2[node]){
                cout<<"printing "<<count+1<< "th SCC:";
                dfs(node,visited2,adjNew);
                count=count+1;
                cout<<endl;
            }
        }

        return count;
        
	}
};

int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,0,0);
    g.addEdge(2,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,6,0);
    g.addEdge(6,4,0);
    g.addEdge(6,7,0);
    cout<<g.countSCC(8);
    return 0;
}