#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;

//custom comp or lamda function
class mycomp{
    public:
    bool operator()(pair<int,int>a,pair<int,int>b){
        //calculate distance->to origin so we only write x^2 + y^2
        int distA=a.first*a.first + a.second*a.second;
        int distB=b.first*b.first + b.second*b.second;
        //return based on which is smaller ie closer to origin
        return distA > distB;
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>>ans;
        //Priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp>pq;
        //we can calculate the dist of each point to orign and then using cutsom comp based on the dist save the closest at the top of the heap ie min heap

        for(auto p:points){
            //insert each point as a pair  in priority queue
            pq.push({p[0],p[1]});
        }

        // jab tak pq->is not empty and k is not 0 store in ans
        while(!pq.empty() && k--){
            auto& top=pq.top();
            ans.push_back({top.first,top.second});
            pq.pop();
        }

        return ans;


        
    }

int main(){

}