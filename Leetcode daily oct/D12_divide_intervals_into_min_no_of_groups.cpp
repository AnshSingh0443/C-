#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

    int minGroups(vector<vector<int>>& intervals) {
        // to be in a group ones start pt should he greater than other ends pt
        // current_Start>end

        //step 1 :sort based on start time
        sort(begin(intervals),end(intervals));

        //step 2:min heap to store end pts of intervals
        priority_queue<int,vector<int>,greater<int>>pq;

        //step 3:process each interval  
        for(vector<int>&interval:intervals){
            int current_Start=interval[0];
            int current_End=interval[1];

            //check if it can be put in group
            if(!pq.empty() && current_Start > pq.top()){
                //meaing it is greater than the min end pt->can be put in the group
                pq.pop();
                //pop prev end pt and push new one
                pq.push(current_End);
            }else{
                //not in any current group create new by adding its end pt to the ,in heap
                pq.push(current_End);
            }
        
        }

        //no of groups = min hheap size
        return pq.size();
        
    }


int main(){

}