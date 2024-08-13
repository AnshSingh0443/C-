#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum/description/
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int len=INT_MAX;

        while(j<nums.size()){
            sum=sum+nums[j];
            while(sum>=target){
                //update len and minimize window
                len=min(len,j-i+1);
                //now try to minimize->sum decrease karne k baad bhi greater than equal to ttarget hai kya
                sum=sum-nums[i];
                i++;
            }
            j++;
        }
        if(len==INT_MAX){
            return 0;
        }else
            return len;
    }
int  main(){
    // Input: target = 7, nums = [2,3,1,2,4,3]
    // Output: 2
    // Explanation: The subarray [4,3] has the minimal length under the problem constraint.
    vector<int>nums={2,3,1,2,4,3};
    int target=7;
    cout<<minSubArrayLen(target,nums);

}