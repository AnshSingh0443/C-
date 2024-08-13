#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
    void permuteUniqueHelper(vector<int>& nums,vector<vector<int>>&ans,int index){
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        //method 2->using map to keep track of already swapped nums[i]
        unordered_map<int,bool>visited;
        for (int i = index; i < nums.size(); i++) {
            if(visited.find(nums[i])!=visited.end()){
                continue;//->skip
            }
            visited[nums[i]]=true;
            swap(nums[i], nums[index]);
            //swap with next index elem
            permuteUniqueHelper(nums,ans, index+1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permuteUniqueHelper(nums,ans,0);  
        //Method 1->use a set
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

}