#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    //1.--->first window of k size
    for(int i=0; i<k; i++){
        //1.1--->chote element remove krdo, 
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        //1.2--->inserting index, so tht we can checkout of window element
        dq.push_back(i);
    }

    //2.--->store answer for first window
    ans.push_back(nums[dq.front()]);

    //3---->remaining windows ko process
    for(int i=k; i<nums.size(); i++) {
        //3.1--->out of window element ko remove krdia 
        if(!dq.empty() && i-dq.front() >= k) {
            dq.pop_front();
        }

        //3.2--->ab ferse current element k liyue chotte element 
        //ko remove krna h 
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        //3.3-->inserting index, so tht we can checkout of window element
        dq.push_back(i);

        //3.4--->current window ka answer store krna h 
        ans.push_back(nums[dq.front()]);

    }

    return ans;
    
    
    
}
int main(){
    int k=3;
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    vector<int>ans=maxSlidingWindow(nums,k);

    for(auto i:ans){
        cout<<i<<" "; 
    }

}