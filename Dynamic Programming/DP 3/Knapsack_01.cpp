#include<iostream>
#include<vector>
using namespace std;
//we will traverse from last elem in the array to first one(right to left)
//1.RECURSIVE SOLn->T.C->O(2^N)
int Knapsack_Rec(int weights[],int values[],int index,int capacity){
    //base case-single element
    if(index==0){
        if(weights[index]<=capacity){
            return values[0];
        }else{
            return 0;
        }
    }

    int include=0;
    if(weights[index]<=capacity){
        include=values[index]+Knapsack_Rec(weights,values,index-1,capacity-weights[index]);
    }

    int exclude=0+Knapsack_Rec(weights,values,index-1,capacity);

    return max(include,exclude);

}
//2.Memoization
int knapsack_TOPDOWN(int weights[],int values[],int index,int capacity,vector<vector<int>>&dp){
    //base case-single element
    if(index==0){
        if(weights[index]<=capacity){
            return values[0];
        }else{
            return 0;
        }
    }

    //step 2: check if the value is present in the array
    if(dp[index][capacity]!=-1){
        return dp[index][capacity];
    }

    int include=0;
    if(weights[index]<=capacity){
        include=values[index]+knapsack_TOPDOWN(weights,values,index-1,capacity-weights[index],dp);
    }

    int exclude=0+knapsack_TOPDOWN(weights,values,index-1,capacity,dp);

    //step 3:update in dp
    dp[index][capacity]=max(include,exclude);
    return dp[index][capacity];
}

//3.tabulation
int knapsack_BOTTOMUP(int weights[],int values[],int n,int capacity){
    //step 1:create a dp array
    vector<vector<int>>dp(n,vector<int>(capacity+1,0));
    //step 2:observe the base 
    for(int w=weights[0];w<=capacity;w++){
        if(weights[0]<=capacity){
            dp[0][w]=values[0];
        }else{
            dp[0][w]=0;
        }
    }

    //step  3:reverse flow of topdown
    //       :capcity->0 to cap and n->o to n


    for(int index=1;index<n;index++){

        for(int wt=0;wt<=capacity;wt++){
            int include=0;
            if(weights[index]<=wt){
                include=values[index] + dp[index-1][wt-weights[index]];
            }

            int exclude=0+dp[index-1][wt];

            //step 3:update in dp
            dp[index][wt]=max(include,exclude);
           

        }

    }

    return dp[n-1][capacity];//max values when no of elms=last elm(n-1) and with capacity=capacity


}

//4.th space optimized

int solveUsingSO(int weight[], int value[], int n, int capacity) {

    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    for(int w = weight[0]; w<=capacity; w++) {
        if(weight[0] <= capacity) {
            prev[w] =  value[0];
        }
        else
         prev[w] =  0;
    }

    for(int index=1; index<n; index++) {
        for(int wt=0; wt<=capacity; wt++) {
        //include and exclude
        int include = 0;
        if(weight[index] <= wt)
            include = value[index] + prev[wt - weight[index]];
        
        int exclude = 0 + prev[wt];
        
        curr[wt]= max(include, exclude);
        }
        //shift
        prev = curr;
    }
    return prev[capacity];  
}
int solveUsingSO2(int weight[], int value[], int n, int capacity) {

  
  vector<int> curr(capacity+1, 0);

    for(int w = weight[0]; w<=capacity; w++) {
        if(weight[0] <= capacity) {
        curr[w] =  value[0];
        }
        else
        curr[w] =  0;
    }

    for(int index=1; index<n; index++) {
        for(int wt=capacity; wt>=0; wt--) {
            //include and exclude
            int include = 0;
            if(weight[index] <= wt)
                include = value[index] + curr[wt - weight[index]];
            
            int exclude = 0 + curr[wt];
            
            curr[wt]= max(include, exclude);
        }
        
    }
    return curr[capacity];  
}

int main(){
    int weights[]={4,5,1};
    int values[]={1,2,3};
    int n=3;//size of array
    int capacity=4;
    int ans=Knapsack_Rec(weights,values,n-1,capacity);

    cout<<ans<<endl;

    //solving using dp
    //step  1:create a dp array since there are two params that are changing in fxn calls
    //       :capacity and index ->2D dp array
    vector<vector<int>>dp(n+1,vector<int>(capacity+1,-1));
    // dp[index][capacity]=max value at elem at index=index and with capacity=capacity
    int ans1=knapsack_TOPDOWN(weights,values,n-1,capacity,dp);
    
    cout<<ans1<<endl;

    int ans2=knapsack_BOTTOMUP(weights,values,n,capacity);
    cout<<ans2<<endl;
}