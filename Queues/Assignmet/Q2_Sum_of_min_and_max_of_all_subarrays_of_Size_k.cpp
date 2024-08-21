#include<iostream>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

int total_sum_of_maxs_and_mins_in_SlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    deque<int> dq2;
    int  ans=0;

    //1.--->first window of k size
    for(int i=0; i<k; i++){
        //1.1--->chote element remove krdo, 
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        //reverse for min->bade elemnet remove karo
        while(!dq2.empty() && nums[i] <= nums[dq2.back()]) {
            dq2.pop_back();
        }
        //1.2--->inserting index, so tht we can checkout of window element
        dq.push_back(i);
        dq2.push_back(i);
    }

    //2.--->store answer for first window->sum=max+min
    ans +=nums[dq.front()]+nums[dq2.front()];
    
   

    //3---->remaining windows ko process
    for(int i=k; i<nums.size(); i++) {
        //3.1--->out of window element ko remove krdia 
        if(!dq.empty() && i-dq.front() >= k) {
            dq.pop_front();
        }
        //min->out of window
        if(!dq2.empty() && i-dq2.front() >= k) {
            dq2.pop_front();
        }

        //3.2--->ab ferse current element k liyue chotte element 
        //ko remove krna h 
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        //bade ko remove for min
        while(!dq2.empty() && nums[i] <= nums[dq2.back()]) {
            dq2.pop_back();
        }
        //3.3-->inserting index, so tht we can checkout of window element
        dq2.push_back(i);
        dq.push_back(i);

        //3.4--->current window ka answer store krna h 
        // ans.push_back(nums[dq.front()]);
        ans+=nums[dq.front()]+nums[dq2.front()];

    }

    return ans;
    
    
    
}

int main(){
    vector<int>nums={2,5,-1,7,-3,-1,2};
    //ans should be 18
    cout<<total_sum_of_maxs_and_mins_in_SlidingWindow(nums,4);


}