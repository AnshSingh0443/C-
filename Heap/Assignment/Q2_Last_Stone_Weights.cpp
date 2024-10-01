#include<iostream>
#include<vector>
#include<queue>

using namespace std;

    int lastStoneWeight(vector<int>& stones) {
        //using priority queue->max heap stone with most weights on top
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        //we know that at the end there is at most one stone left

        while(pq.size() > 1){
            //first stone
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            //smash em
            // if(x==y){
            //     //do nothidng
            // }
            if(x > y){
                pq.push(x-y);
            }
        }

        if(pq.empty()){
            return 0;
        }
        return pq.top();
        
    }



int main(){
   

}