#include<iostream>
#include<vector>
using namespace std;
void subsetsHelper(vector<int>& nums,vector<vector<int>>&ans,vector<int>&v,int index){
    if(index>=nums.size()){
        ans.push_back(v);
        return;
    }

    //pick
    v.push_back(nums[index]);
    subsetsHelper(nums,ans,v,index+1);

    //not pick
    v.pop_back();
    subsetsHelper(nums,ans,v,index+1);

    //another way->
    // ans.push_back(v);
    // for(int i=index;i<nums.size();i++){
    //     v.push_back(nums[i]);
    //     subsetsHelper(nums,ans,v,i+1);
    //     v.pop_back();
    // }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>v;
    subsetsHelper(nums,ans,v,0);

    return ans;
}
int main(){
    vector<int>nums={1,2,3};
    subsets(nums);

}