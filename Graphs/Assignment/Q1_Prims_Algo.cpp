#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
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
    //PRIMS ALGO
    int minSpanningTree(int n){
        //1.to store each node 
        vector<int>keys(n,INT_MAX);
        vector<int>MST(n,false);
        vector<int>parent(n,-1);
        //set src ->0
        keys[0]=0;

        while(true){
            //step 1->find  min value node from key
            int u=getminNode(keys,MST);

            if(u==-1){
                break;//no min found ie all nodes are in mst
            }

            //step 2:mark u visited in mst
            MST[u]=true;

            //step  3->get all adjacents
           
                for(auto nbr:adjList[u]){
                    int v=nbr.first;
                    int wt=nbr.second;

                    if(MST[v]==false && wt< keys[v]){
                        //update weight
                        keys[v]=wt;
                        //set parent
                        parent[v]=u;

                    }

                }
            
        }   
        //parent->contains the mst & keys contains the weight
        int sum=0;
        for(int i=0;i<keys.size();i++){
            sum +=keys[i];
        }
        return sum;
    }


};

//NEETCODE IMPLEMENTATION OF PRIMS ALGO
// Given a list of edges of a connected undirected graph,
// with nodes numbered from 1 to n,
// return a list edges making up the minimum spanning tree.
vector<pair<int, int>> mst(vector<vector<int>>& edges, int n) {
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 1; i < n + 1; i++) {
        adj[i] = vector<pair<int, int>>();
    }
    for (vector<int> edge : edges) {
        int n1 = edge[0], n2 = edge[1], weight = edge[2];
        adj[n1].push_back(make_pair(n2, weight));
        adj[n2].push_back(make_pair(n1, weight));
    }

    // Initialize the heap by choosing a single node
    // (in this case 1) and pushing all its neighbors.
    priority_queue<tuple<int,int, int>, vector<tuple<int,int, int>>, greater<tuple<int, int, int>>> minHeap; 
    for (pair<int, int> neighbor : adj[1]) {
        int node = neighbor.first, weight = neighbor.second;
        minHeap.push({weight, 1, node});
    }
    
    vector<pair<int, int>> mst;
    unordered_set<int> visit;
    visit.insert(1);
    while (visit.size() < n) {
        tuple<int, int, int> cur = minHeap.top();
        minHeap.pop();
        int w1 = get<0>(cur), n1 = get<1>(cur), n2 = get<2>(cur);

        if (visit.count(n2) > 0) {
            continue;
        }
        mst.push_back({n1, n2});
        visit.insert(n2);
        for (pair<int, int> p : adj[n2]) {
            int neighbor = p.first, weight = p.second;
            if (visit.count(neighbor) == 0) {
                minHeap.push({weight, n2, neighbor});
            }
        }
    }
    return mst;
}


int main(){
    //implementing adj list
    // we write down nodes and attach a list to each node
    // the list contains all the other vertex/nodes which is connected to that node in case of undirected graph
    // or the list contains the nodes which we can move to from the that node in case of directed graph



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