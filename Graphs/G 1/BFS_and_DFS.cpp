#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template<typename T>

//list<int>adj
//adj->{1,2,14.....etc}
class Graph{
    public:
    //adj list created
    unordered_map<T,list<T> >adjList;

    void addEdge(T u,T v,bool direction){
        //direction=0->undirected graph
        //direction=1->directed graph
        adjList[u].push_back(v);//edge u to v
        if(direction==0){
            adjList[v].push_back(u);//edge v to u incase of undirected graph
        }
    }

    void printList(){
        for(auto node:adjList){
            cout<<node.first<<"-> ";
            for(auto neighbours:node.second){
                cout<<neighbours<<",";
            }
            cout<<endl;
        }
        

    }

    //bfs->BREADTH FIRST SEARCH->when we visit a  node we also visit all the neighbouring nodes before moving to another one
    //T.C->o(v+e) where v->no of nodes/vertex and e->no of edges
    void BFS(int src){
        queue<int>q;
        unordered_map<int,bool>visited;//->keep track of which node is vistied

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            cout<<frontNode<<" ";
 
            //insert neiigbours
            for(auto neighbour:adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }

    }
    void dfs(int src, unordered_map<int, bool>& visited) {
        cout << src << " ";
        visited[src] = true;

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour] ) {
                dfs(neighbour, visited);
            }
        }
    }



};



int main(){
    Graph<int> g;

    int n=8;//no of nodes
    
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);

    g.printList();
    cout<<endl;
    cout<<"BFS Traveral:->";
    g.BFS(0);

    // for disconneted graph->send each node/vertex as source to fully traverse the graph
    // unordered_map<int,bool>visited;
    // run a loop for each node->(taken as src)
    // for(int i=0;i<=n;i++){
    //     if(!visited[i]){
    //         g.BFS(i,visited);//modify the bfs fxn to  take visited(pass by ref) map as argument 
    //     }

    // }
    cout << endl << "DFS Traversal:-> ";
    unordered_map<int, bool> visited2;
    // for disconneted graph->send each node/vertex as source to fully traverse the graph
    // for(int i=0; i<n; i++) {
    //     if(!visited2[i]) {
    //         g.dfs(i, visited2);
    //     }
    // }
    g.dfs(0,visited2);





}