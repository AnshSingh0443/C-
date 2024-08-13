#include<iostream>
#include<vector>
using namespace std;
void combinationSum_Helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&v,int index){
    //base case->target reached or sum becomes > target
    if(target==0){
        ans.push_back(v);
        return;
    }
    if(target<0){
        return;
    }

    //instead of starting i from 0 expect initially we start it from index so we get unique combination of sum eg->223 only and not 322 or something like this
    for(int i=index;i<candidates.size();i++){
        v.push_back(candidates[i]);//curr element in the array v
        combinationSum_Helper(candidates,target-candidates[i],ans,v,i);
        //backtrack->when the sum is greater remove the elem from v
        v.pop_back();

    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>v;
    combinationSum_Helper(candidates,target,ans,v,0);
    return ans;

}
int main(){
//     //PROBLEM STATEMENT
//     Given an array of distinct integers candidates and a target integer target, 
//     return a list of all unique combinations of candidates where the chosen numbers sum to target. 
//     You may return the combinations in any order.
//     The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
//     frequency
//     of at least one of the chosen numbers is different.
//     The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

        //example
        // Input: candidates = [2,3,6,7], target = 7
        // Output: [[2,2,3],[7]]
        // Explanation:
        // 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
        // 7 is a candidate, and 7 = 7.
        // These are the only two combinations.
        vector<int> candidates={2,3,6,7};
        int target = 7;

       



}
