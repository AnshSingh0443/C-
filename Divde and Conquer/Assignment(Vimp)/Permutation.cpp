#include<iostream>
#include<vector>
using namespace std;
    void permuteHelper(vector<int>& nums,vector<vector<int>>&ans,int index){
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            //swap with next index elem
            permuteHelper(nums,ans, index+1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permuteHelper(nums,ans,0);

        return ans;
        
    }
int main(){
    vector<int>nums={1,2,3};
    permute(nums);


}