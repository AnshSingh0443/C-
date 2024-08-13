#include<iostream>
#include<vector>
using namespace std;


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
        if(i>index && candidates[i]==candidates[i-1]){
            continue;
        }
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
    //PROBLEM STATEMENT->
    // Given a collection of candidate numbers (candidates) and a target number (target),
    // find all unique combinations in candidates where the candidate numbers sum to target.
    // Each number in candidates may only be used once in the combination.
    // Note: The solution set must not contain duplicate combinations.

 

    // Example :
    // Input: candidates = [10,1,2,7,6,1,5], target = 8
    // Output: 
    // [
    // [1,1,6],
    // [1,2,5],
    // [1,7],
    // [2,6]
    // ]
    vector<int> candidates={2,3,6,7};
    int target = 7;

}