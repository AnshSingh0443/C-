#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
// template<typename T>

//list<int>adj
//adj->{1,2,14.....etc}
class WeightedGraph{
    public:
    //adj list created with list that conatins pair->node and weightes/dis to reach the node
    unordered_map<int,list<pair<int,int> >>adjList;

    void addEdge(int u,int v,int weight,bool direction){
        //direction=0->undirected graph
        //direction=1->directed graph
        adjList[u].push_back({v,weight});//edge u to v with weight
        if(direction==0){
            adjList[v].push_back({u,weight});//edge v to u with weight incase of undirected graph 
        }
    }

    void printList(){
        for(auto node:adjList){
            cout<<node.first<<"-> ";
            for(auto neighbours:node.second){
                cout<<"("<<neighbours.first<<","<<neighbours.second<<") ,";
            }
            cout<<endl;
        }
        

    }

};

class Graph{
    public:
    //adj list created
    unordered_map<int,list<int> >adjList;

    void addEdge(int u,int v,bool direction){
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

};

int main(){
    //implementing adj list
    // we write down nodes and attach a list to each node
    // the list contains all the other vertex/nodes which is connected to that node in case of undirected graph
    // or the list contains the nodes which we can move to from the that node in case of directed graph

    Graph g;
    //let g->undirected
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // cout<<endl;
    // g.printList();

    //let g->directed edge
    cout<<"Printing directed graph adj list";
    //g.addEdge(SrcNode,DestNode,Direction)
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,1);
    cout<<endl;
    g.printList();

    cout<<endl;

    //let wg->directed weighted graph
    cout<<"Printing  directed weighted graph adj list";
    WeightedGraph wg;
    //wg.addEdge(SrcNode,DestNode,Weight,Direction)
    wg.addEdge(0,1,5,1);
    wg.addEdge(1,2,8,1);
    wg.addEdge(0,2,6,1);
    cout<<endl;
    wg.printList();





}