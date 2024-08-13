#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
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
    int getminNode(vector<int>keys,vector<int>&MST){
        int min=INT_MAX;
        int index=-1;
        for(int i=0;i<keys.size();i++){
            if(keys[i]<min && MST[i]==false){
                min=keys[i];
                index=i;
            }
        }
        return index;
    }
    static bool cmp(vector<int>a,vector<int>b){
        //u v w
        //wt->arra[2]
        return a[2]<b[2];
    }
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node){
            return node;
        }
        parent[node]=findParent(parent,parent[node]);
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u=findParent(parent,u);
        v=findParent(parent,v);
        if(rank[u]>rank[v]){
            parent[v]=u;
            rank[u]++;
        }else{
            parent[u]=v;
            rank[v]++;
        }
    }
    //KRUSHKAL ALGO
    int minSpanningTree(int n){
        //1.to store parent of each node / representative of nodes belonging to that component
        vector<int>parent(n);
        vector<int>rank(n,0);//using rank we will decide the parent/rep  of that component

        //each node is initially treated as individual componenet
        for(int i=0;i<n;i++){
            //inidividual comp->node is prent of itself
            parent[i]=i;
        }

        //instead of using adjlist we use linear data struct which contains u,v,wt
        vector<vector<int>>edges;
        for(auto nodes:adjList){
           int u=nodes.first;
           for(auto nbr:adjList[u]){
                int v=nbr.first;
                int wt=nbr.second;
                // add u v wt to edges
                edges.push_back({u,v,wt});
           }
            
        }
        //sort edges based on wt
        sort(edges.begin(),edges.end(),cmp);
        int ans=0;

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            u=findParent(parent,u);
            v=findParent(parent,v);

            if(u!=v){
                unionSet(u,v,parent,rank);
                ans=ans+wt;
            }
        }
        return ans;

        
    
    }


};


// class Graph{
//     public:
//     //adj list created
//     unordered_map<int,list<int> >adjList;

//     void addEdge(int u,int v,bool direction){
//         //direction=0->undirected graph
//         //direction=1->directed graph
//         adjList[u].push_back(v);//edge u to v
//         if(direction==0){
//             adjList[v].push_back(u);//edge v to u incase of undirected graph
//         }
//     }

//     void printList(){
//         for(auto node:adjList){
//             cout<<node.first<<"-> ";
//             for(auto neighbours:node.second){
//                 cout<<neighbours<<",";
//             }
//             cout<<endl;
//         }
        

//     }


// };


int main(){
    


    cout<<endl;

    //let wg->undirected weighted graph
    cout<<"Printing  directed weighted graph adj list";
    WeightedGraph wg;
    //wg.addEdge(SrcNode,DestNode,Weight,Direction)
    wg.addEdge(0,1,5,0);
    wg.addEdge(1,2,3,0);
    wg.addEdge(0,2,1,0);
    cout<<endl;
    wg.printList();

    int n=3;//node ->0 ,1, 2 min wt MSt should be 4

    int res=wg.minSpanningTree(n);
    cout<<res;





}