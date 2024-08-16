#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<list>

using namespace std;
    unordered_map<int,list<pair<int,int>>>adjList;
    vector<int> dijkstraAlgo(int src,int n){
        vector<int>dist(n,INT_MAX);
        set<pair<int,int>>st;
        dist[src] = 0;
        st.insert({0,src});
        while(!st.empty()){
            // Fetch the smallest or first element from set
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int node = top.second;
            // pop from set
            st.erase(st.begin());
            // Traverse neighbour
            for(auto nbr : adjList[node]){
                if(nodeDistance + nbr.second < dist[nbr.first]){
                    // update distance
                    // finding entry in the set
                    auto result = st.find({dist[nbr.first],nbr.first});
                    // if found -> delete 
                    if(result != st.end()){
                        st.erase(result);
                    }
                    // update in dist array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert({dist[nbr.first],nbr.first});
                }
            }
        }
        return dist;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //dijkastra
        //atke src as k and dest as other nodes find the max dis it to reach any node
        //that will be the min time it takes to reach a node


       
        //making a adjacency list out of times[]
        for(auto edge:times){
            int src=edge[0];
            int dest=edge[1];
            int time=edge[2];
            adjList[src].push_back({dest,time});
        }
        vector<int>res=dijkstraAlgo(k,n+1);

        int ans=INT_MIN;

        for(int i=1;i<res.size();i++){
            cout<<res[i]<<" ";
            if(res[i] > ans){
                ans=res[i];
            }
        }
        if(ans==INT_MAX){
            ans=-1;
        }
        return ans;

    }

int main(){
    return 0;
}