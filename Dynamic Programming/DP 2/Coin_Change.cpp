#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursion(vector<int>& arr,int target) {
    //Base case
    if(target==0){
        return 0;
    }
    if(target<0){
        return INT_MAX;
    }

    //solve one case
    //for each element in the array there will be a function call for every element in the array
    int mini=INT_MAX;
    for(int i=0;i<arr.size();i++){
        //functionn call
        int ans = solveRecursion(arr,target-arr[i]);// ans here is the no of elements req to reach target-arr[i]
        
        if(ans!=INT_MAX)//->means ans is valid value target sum is reached
        mini=min(mini,ans+1);// we add +1 in order to reach target since ans->ans here is the no of elements req to reach target-arr[i]
    }
    return mini;

}

//memoization + recursion
// T.C->o(target/amount)
// S.c->o(n+n)
int solveToptoBottom(vector<int>& arr,int target,vector<int>&dp){
    //Base case
    if(target==0){
        return 0;
    }
    if(target<0){
        return INT_MAX;
    }
    // step 2:check if ans is present in the dp array
    if(dp[target]!=-1){
        return dp[target];
    }

    //solve one case
    //for each element in the array there will be a function call for every element in the array
    int mini=INT_MAX;
    for(int i=0;i<arr.size();i++){
        //functionn call
        int ans = solveToptoBottom(arr,target-arr[i],dp);// ans here is the no of elements req to reach target-arr[i]
        
        if(ans!=INT_MAX)//->means ans is valid value target sum is reached
        mini=min(mini,ans+1);// we add +1 in order to reach target since ans->ans here is the no of elements req to reach target-arr[i]
    }
    //step 3: update the Dp array
    dp[target]=mini;
    
    return mini;

}

//Tabulation
//T.C->o(target * coin array.size)
//S.C->o(n)
int solveBottomUp(vector<int>& arr,int target){
    //Step 1:create a dp array
    //since we will be storing minimum no of coins req to amke the target we need to initializa the dp array with INT_MAX 
    vector<int>dp(target+1,INT_MAX);

    //step2:observe the base case
    dp[0]=0;

    //step 3:Reverse flow of top down approach
    for(int i=1;i<=target;i++){
        //i->representing target/amount
        for(int j=0;j<arr.size();j++){
            //j->index for coins
            if(i-arr[j] >=0 && dp[i-arr[j]]!=INT_MAX){
                //valid index + answer exists in the dp array 
                int ans=dp[i-arr[j]];
                dp[i]=min(dp[i],ans+1);

            }
        }
    }
    return dp[target];
}

int main() {
//PRoblem statement 
//->an array exists of length n that contains only unique elements
//->and a target is given and using the elements in the array we need to make up the target
//->we need to return the minimum no of elements that are required to reach target sum

vector<int>arr{1,5,7};
int target=8;// 5 can be made by 11111,1211,221
int ans=solveRecursion(arr,target);
cout<<"the answer using recurison is :"<<ans<<endl;

//solving using dp
//step 1: create a dp array
vector<int>dp(target+1,INT_MAX);
int ans2=solveToptoBottom(arr,target,dp);
cout<<"The answer using DP(top dowm is) : "<<ans<<endl;

//solvong using dp(tabulation/bottom up)
int ans3=solveBottomUp(arr,target);
cout<<"The answer using DP(bottom up is) : "<<ans3<<endl;

} 