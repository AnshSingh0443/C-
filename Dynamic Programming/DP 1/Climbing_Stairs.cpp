#include<iostream>
#include<vector>
using namespace std;
int solveRecursion(int n){
    //Base case->agar 1st step pe jana hai-> only 1 step is req
    if(n==0||n==1){
        return 1;
    }
    //R.R->nth stair pe jana k liye two ways->ya toh n-1 se jump ->one step or n-2 se jump->  step
    return solveRecursion(n-1)+solveRecursion(n-2);
}

int SolveTopDown(int n,vector<int>&dp){
    //Base case->agar 1st step pe jana hai-> only 1 step is req
    if(n==0||n==1){
        return 1;
    }
    //step 2:check if ans is present in the dp array
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=SolveTopDown(n-1,dp)+SolveTopDown(n-2,dp);

    return dp[n];

}

int solveBottomUp(int n){
    //step 1:create a dp array
    vector<int>dp(n+1,-1);
    //step 2:observe base cases
    dp[0]=1;
    dp[1]=1;
    //step 3: reverse slow of top down
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}
int main(){
    int n=4;
    
    cout<<"No of ways to reach "<<n<<"th stair(Recursion) :"<<solveRecursion(n)<<endl;//total num of ways by which we can reach 3rd stair

    //using dp
    //step 1:Create a array dp
    vector<int>dp(n+1,-1);
    cout<<"No of ways to reach "<<n<<"th stair(dp->TOPDOWN) :"<<SolveTopDown(n,dp)<<endl;


    cout<<"No of ways to reach "<<n<<"th stair(dp->BOTTOMUP) :"<<solveBottomUp(n)<<endl;





}