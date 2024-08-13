#include<iostream>
#include<vector>
using namespace std;
int main(){
    //IMPLEMENTING ADJ MATRIX
    //no of nodes
    int n;
    cout<<"Enter the no of nodes/vertex:";
    cin>>n;
    cout<<endl;
    int e;
    //no of edges
    cout<<"Enter the no of edges:";
    cin>>e;
    cout<<endl;

    //create a adj matrix->keeps the data of edges present between nodes in form of 2d matrix
    vector<vector<int>>adj(n,vector<int>(n,0));//a adj matrix of n x n is created which is initialized to 0 

    //input edges
    cout<<"what are those vertices:"<<endl;
   
    for(int i=0;i<e;i++){
        int u,v;
        cout<<"edge between ";
        cin>>u;
        cout<<" "<<"and";
        cin>>v;

        //mark in the adj matrix
        // to make this weighted instead of 1 we insert weight
        adj[u][v]=1;
    }

    //print the adj matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<" "<<adj[i][j];
        }
        cout<<endl;
    }

}