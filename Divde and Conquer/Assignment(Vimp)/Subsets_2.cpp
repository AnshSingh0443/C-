#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    void subsetswithdupHelper(vector<int>& nums,vector<vector<int>>&ans,vector<int>&v,int index){
        if(index>=nums.size()){
            ans.push_back(v);
            return;
        }

        //pick
        v.push_back(nums[index]);
        subsetswithdupHelper(nums,ans,v,index+1);
        v.pop_back();

        //not pick->skip
        //to avoid dupliactes we will count only one occurence of a num and ignore the rest
        while(index+1<nums.size() && nums[index]==nums[index+1]){
            index=index+1;
        }
        subsetswithdupHelper(nums,ans,v,index+1);

        //another way->
        // ans.push_back(v);
        // for(int i=index;i<nums.size();i++){
        //     v.push_back(nums[i]);
        //     subsetsHelper(nums,ans,v,i+1);
        //     v.pop_back();
        // }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        subsetswithdupHelper(nums,ans,v,0);
        //using this only 15 test cases passed
        // set<vector<int>>st;
        // for(auto e:ans){
        //     st.insert(e);
        // }
        // ans.clear();
        // for(auto e:st){
        //     ans.push_back(e);
        // }

        return ans;
        
    }
int main(){

    vector<int>nums={1,2,2};
    subsetsWithDup(nums);

}