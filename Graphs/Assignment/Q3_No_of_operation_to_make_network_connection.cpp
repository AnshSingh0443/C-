#include<iostream>
#include<vector>

using namespace std;
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent,parent[node]);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        //to make connection newtork 
        //we need 2 things
        //1. no of connected components
        //2. no of extraedges
        //3. since we need n-1 edges to connect n componets
        //4. ans= no of coonected comps-1; 
        //5. if(ans>=extraedges)->return ans else return -1

        //we will use disjoint set to implement this

       
        vector<int>rank(n,0);//inititally rank of each node->0
        vector<int>parent(n);//inititally all nodes are treated as individual comps
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int extraEdges=0;
        for(auto connection:connections){
            //conections in bascially a edges list 
            int u=connection[0];
            int v=connection[1];

            u=findParent(parent,u);
            v=findParent(parent,v);

            if(u!=v){
                unionSet(u,v,parent,rank);
            }
            else
                //u===v->same parent->both in same comp->extra edges found
                extraEdges++;
        }
       
        //we  can find the no of connection comps using parent array
        //those node whose parent  are themself are part of diff componennts
        int nocc=0;;//no of connected comp
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                nocc++;
            }
        }
    
        int ans=nocc-1;
        return extraEdges >= ans ? ans:-1;
    }


int main(){
    // Input: n = 4, connections = [[0,1],[0,2],[1,2]]
    // Output: 1
    // Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
    int n=4;
    vector<vector<int>>connections={{0,1},{0,2},{1,2}};
    cout<<makeConnected(n,connections);

}