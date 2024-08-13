#include<iostream>
#include<vector>

using namespace std;

int solveRecursion(vector<int>&nums,int index ){
    //base cases
    if(index>=nums.size()){
        return 0;
    }
    if(nums.size()==0){
        return nums[0];
    }

    //pick the house to rob
    int include=nums[index]+solveRecursion(nums,index+2);

    //dont pick the house
    int exculde=solveRecursion(nums,index+1);
    
    return max(include,exculde);
    
}

//memoization +recursion
int solveToptoBottom(vector<int>&nums,int index ,vector<int>&dp){
    //base cases
    if(index<0){
        return 0;
    }
    if(index==0){
        return nums[0];
    }
    //step 2: check if ans is present in the answer
    if(dp[index]!=-1){
        return -1;
    }

    //pick the house to rob
    int include=nums[index]+solveToptoBottom(nums,index-2,dp);

    //dont pick the house
    int exculde=solveToptoBottom(nums,index-1,dp);

    dp[index]=max(include,exculde);
    
    return dp[index];

}

//tabulation
int solveBottomUp(vector<int>&nums,int index){
    //step 1:create a dp array
    vector<int>dp(index+1,0);
    //step 2:observe the bse cases
    dp[0]=nums[0];
    //step 3:reverse flow of top down
    for(int i=1;i<=index;i++){
        int pick=nums[i];
        if(i>1){
            pick=pick+dp[i-2];
        }
        int notpick=0+dp[i-1];
        dp[i]=max(pick,notpick);
    }
    return dp[index];

}

//space optimization soln
int spaceOptimizedSoln(vector<int>&nums,int index){
    int prev2=0;
    int prev1=nums[0];
    int curr=0;
    for(int i=1;i<=index;i++){
       int pick=nums[i];
       if(i>1){
         pick=pick+prev2;
       }
       int notpick=0+prev1;

       curr=max(pick,notpick);
       prev2=prev1;
       prev1=curr;


    }
    return prev1;
}


int main(){
    //two adjacent houses cannot be robbed
    //rob such that the amount is maxm

    vector<int>nums{1,2,3,1};

    cout<<"max robbery(recursion)-> "<<solveRecursion(nums,0)<<endl;


    //Step 1:create a dp array
    // in dp we will store the maximum amount robed till that index
    // eg dp[i]= max amount robbed till index=i
    vector<int>dp(nums.size()+1,-1);
    cout<<"max robbery(dp->topdown)-> "<<solveToptoBottom(nums,nums.size()-1,dp)<<endl;

    cout<<"max robbery(dp->bottomUp)-> "<<solveBottomUp(nums,nums.size()-1)<<endl;    

    //space optimized soln
    cout<<"max robbery(dp->space optimized)-> "<<spaceOptimizedSoln(nums,nums.size()-1)<<endl;


}