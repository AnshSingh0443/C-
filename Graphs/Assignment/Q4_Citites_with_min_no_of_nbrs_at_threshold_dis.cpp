#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<list>
//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

using namespace std;
    int dijkstraAlgo(int src,int n, unordered_map<int,list<pair<int,int>>>&adjList,int &distanceThreshold){
        vector<int>dist(n,INT_MAX);
        set<pair<int,int>>st;
        dist[src] = 0;
        st.insert({0,src});
        //since we dont want alll the dis and only want those who dis is <=threshold
        int reachableCitits=0;
        while(!st.empty()){
            // Fetch the smallest or first element from set
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int node = top.second;

            //what is a reachable citiy->node is not itself and nodedist is <=threshold
            if(node!=src && nodeDistance <=distanceThreshold){
                reachableCitits++;
            }

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
        return reachableCitits;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //we will make a adj list out of edges
        unordered_map<int,list<pair<int,int>>>adjList;

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adjList[u].push_back({v,wt});
            //bidrection given
            adjList[v].push_back({u,wt});

        }
        int city=0;
        int minReachableCitites=INT_MAX;
        for(int u=0;u<n;u++){
            int reachableCitites=dijkstraAlgo(u,n,adjList,distanceThreshold);

            //now we have reachablecities for each node as source
            //save min
            if(reachableCitites <=minReachableCitites){
                //= is taken to return thr city with greater no if there the multiple same  
                minReachableCitites=reachableCitites;
                city=u;
            }
        }
        return city;
        
    }
int main(){
    // Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
    // Output: 3
    // Explanation: The figure above describes the graph. 
    // The neighboring cities at a distanceThreshold = 4 for each city are:
    // City 0 -> [City 1, City 2] 
    // City 1 -> [City 0, City 2, City 3] 
    // City 2 -> [City 0, City 1, City 3] 
    // City 3 -> [City 1, City 2] 
    // Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
    //https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
}