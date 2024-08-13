#include<iostream>
#include<vector>
using namespace std;
//1.using recursion
bool getSubsetwithsum_Rec(vector<int>&nums,int index,int target){
    // base case
    if(index>=nums.size()){
        return false;
    }
    if(target<0){
        return false;
    }
    if(target==0){
        return true;
    }

    //include and exculde for subsets
    bool include=getSubsetwithsum_Rec(nums,index+1,target-nums[index]);
    bool exclude=getSubsetwithsum_Rec(nums,index+1,target);

    //using include and exclude we may or may not find the subset with sum=target 
    bool ans=(include || exclude);
    return ans;
}

//2.Memoization
bool getSubsetwithsum_TOPDOWN(vector<int>&nums,int index,int target,vector<vector<int>>&dp){
    // base case
    if(index>=nums.size()){
        return false;
    }
    if(target<0){
        return false;
    }
    if(target==0){
        return true;
    }
    //step 2: check in dp array
    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    

    //include and exculde for subsets
    bool include=getSubsetwithsum_Rec(nums,index+1,target-nums[index]);
    bool exclude=getSubsetwithsum_Rec(nums,index+1,target);

    //using include and exclude we may or may not find the subset with sum=target 
    //step 3: update the dp array
    dp[index][target]=(include || exclude);
    return  dp[index][target];
}
//3.Tabulation
bool getSubsetwithsum_BOTTOMUP(vector<int>&nums,int index,int target){
    int n=nums.size();
    // step 1:create a dp array
    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

    //step 2: observe base cases->when target is 0 we return true
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
   
   //step 3: reverse flow of top down
   //index->n-1 to 0 outer loop
   for(int index=n-1;index>=0;index--){
        //target rep by t->0 to target inner loop
        for(int t=1;t<=target;t++){
            //replace rec calls with dp
            bool include=0;
            if(t-nums[index]>=0){
                //valid index
                include=dp[index+1][t-nums[index]];
            }
            
            bool exclude=dp[index+1][t];
            dp[index][t]=(include || exclude);
            
        }
   }
   //our answer end se banta hua aa raha n-1 to 0 
   // so final answer [0][target] pr store hoga na ki [n-1][target] pr 
    return dp[0][target];
}

bool solveUsingTabulationSO(vector<int>& nums, int target) {
    int n = nums.size();
        
    vector<int> curr(target+1, 0);
    vector<int> next(target+1, 0);

    curr[0] = 1;
    next[0] = 1;

    for(int index = n-1; index>=0; index--) {
        for(int t = 1; t<=target; t++) {
            bool include = 0;
            if(t-nums[index] >=0)
                include = next[t-nums[index]];

            bool exclude = next[t];

            curr[t] = (include || exclude);
        }
        next = curr;
    }

    return next[target];
}





bool canPartition(vector<int>&nums){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    if(sum & 1){
        //odd->we cannot obtain two  equal subsets with odd sum
        return false;
    }
    int target=sum/2;
    int index=0;
    // bool ans=getSubsetwithsum_Rec(nums,index,target);
    // return ans;
    int n=nums.size();

    //step 1:create a dp array
    // vector<vector<int>>dp(n,vector<int>(target+1,-1));
    bool ans=getSubsetwithsum_BOTTOMUP(nums,index,target);
    return ans;

}




int main(){
    vector<int>nums{1,5,11,6};
    cout<<"parition with Equal Subset sum is "<<canPartition(nums);

}