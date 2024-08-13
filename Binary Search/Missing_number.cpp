#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int missingNumber(vector<int>& nums) {
    //sort
    sort(nums.begin(),nums.end());
    //using binary search
    int s=0;
    int e=nums.size()-1;
    int mid=s+(e-s)/2;
    
    while(s<=e){
        if(nums[mid]>mid){
            // num is missing from the left side
            // search in left
            e=mid-1;//mid can also be missing num
        }else{
            // num is missing from right
            // search in right
            s=mid+1;
        }
        mid=s+(e-s)/2;

    }
    return s;

    
}
int main(){
    vector<int>nums{9,6,4,2,3,5,7,0,1};//missing-8
    // 1st approach-Xor
    // int res = nums.size();
    // for(int i=0; i<nums.size(); i++){
    //     res ^= i;
    //     res ^= nums[i];
    // }
    // cout<<res;


    //2nd apporach-sum
    // expected sum - calculated sum = missing num
    // int n=nums.size();
    // // expected sum
    // int sum=n*(n+1)/2;//sum from o to n
    // //calculated sum
    // int calsum=0;
    // for(int i=0;i<n;i++){
    //     calsum=calsum+nums[i];
    // }
    // int missing_num=sum-calsum;
    // cout<<"missing num is"<<missing_num;


    //3rd approach sort and then binary search
    cout<<missingNumber(nums);

}