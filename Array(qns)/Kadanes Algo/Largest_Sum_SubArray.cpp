#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;

// Brute Force: O(n^2)
int bruteForce(vector<int>& nums) {
    int maxSum = nums[0];

    for (int i = 0; i < nums.size(); i++) {
        int curSum = 0;
        for (int j = i; j < nums.size(); j++) {
            curSum += nums[j];
            maxSum = max(maxSum, curSum);
        }
    }
    return maxSum;
}

// Kadane's Algorithm: O(n)
int kadanes(vector<int>& nums) {
    int maxSum = nums[0];//or assign INT_MIN
    int curSum = 0;

    for (int i=0;i<nums.size();i++) {
        curSum = max(curSum, 0);//check if curr sum is +ve or not if it is negative then assign currsum=0
        curSum = curSum + nums[i];//add the no to current sum
        maxSum = max(maxSum, curSum);//assign maxsum if currsumm get larger
    }
    return maxSum;
}

// Return the left and right index of the max subarray sum,
// assuming there's exactly one result (no ties).
// Sliding window variation of Kadane's: O(n)
vector<int> slidingWindow(vector<int> nums) {
    int maxSum = nums[0];
    int curSum = 0;
    int maxL = 0, maxR = 0;//these two will represent the left and right index of subarray with maximum sum
    int L = 0;
    //use a pointer R to iterate through the array
    for (int R = 0; R < nums.size(); R++) {
        if (curSum < 0) {
            //when currsum becomes -ve we assign it back to zero
            curSum = 0;
            L = R;//start anew
        }
        curSum += nums[R];
        if (curSum > maxSum) {
            //assign max sum
            maxSum = curSum;
            //assign these to represent the left and right index of subarray with maximum sum
            maxL = L; 
            maxR = R;     
        }    
    }    
    return vector<int>{maxL, maxR};
}

int main(){
    vector<int>nums{4,-1,2,-7,3,4};
    cout<<"max sum is ->"<<kadanes(nums);
    vector<int>index=slidingWindow(nums);
    cout<<endl<<"subarray is->";

    for(int i=0;i<index.size();i++){
        cout<<index[i]<<" ";
    }

}