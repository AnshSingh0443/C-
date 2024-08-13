#include<iostream>
#include<vector>
using namespace std;

    //GIVES  TLE IN LEETCODE->USE OF DYNAMIC PROGRAMMING REQUIRED

    int solve(vector<int>& nums ,int index){
        //base case->
        if(index>=nums.size()){
            return 0;
           
        }

        //include
        int include=nums[index]+solve(nums,index+2);

        //exclude
        int exclude=0+solve(nums,index+1);

        return max(include,exclude);
        
    }
    int rob(vector<int>& nums) {

        int index=0;
        int ans=solve(nums,index);
        
        return ans;
    }
int main(){
    vector<int>nums{2,1,2,1};
    cout<<rob(nums);

}