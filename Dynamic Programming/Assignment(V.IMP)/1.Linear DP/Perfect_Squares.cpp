#include<iostream>
#include<cmath>
#include<vector>
using  namespace std;
//1.Recursion
int numSquare(int n){
    //base case
    if(n==0){
        return 0;
    }
    if(n<0){
        return 0;
    }

    //solve one case
    int ans=INT_MAX;
    int i=1;
    int end=sqrt(n);

    while(i<=end){
        int perfectSquare=i*i;
        int NoOfPerfectSquares=1+numSquare(n-perfectSquare);
        if(NoOfPerfectSquares<ans){
            ans=NoOfPerfectSquares;
        }
        i++;

    }
    return ans;
    
}

//2.Memoization
int numSquare_TOPDOWN(int n,vector<int>&dp){
    //base case
    if(n==0){
        return 0;
    }
    if(n<0){
        return 0;
    }
    //step 2 :check if answeer is present in the array
    if(dp[n]!=-1){
        return dp[n];
    }

    //solve one case
    int ans=INT_MAX;
    int i=1;
    int end=sqrt(n);

    while(i<=end){
        int perfectSquare=i*i;
        int NoOfPerfectSquares=1+numSquare_TOPDOWN(n-perfectSquare,dp);
        if(NoOfPerfectSquares<ans){
            ans=NoOfPerfectSquares;
        }
        i++;

    }
    //update dp
    dp[n]=ans;
    return dp[n];
    
    
}
//3. Tabulation
int numSquare_BOTTOMUP(int n){
    //step 1 :create a dp array
    vector<int>dp(n+1,0);

    //base case handled during initialization of dp

    //step 3:reverse flow of dp

    for(int i=1;i<=n;i++){
        //replace fxn call with dp and use loop variable accordingly n->i
        int ans=INT_MAX;
        int end=sqrt(i);
        int start=1;

        while(start<=end){
            int perfectSquare=start*start;
            int NoOfPerfectSquares=1+dp[i-perfectSquare];
            if(NoOfPerfectSquares<ans){
                ans=NoOfPerfectSquares;
            }
            start++;
        }
        //update dp
        dp[i]=ans;
        
    }
    return dp[n];
}

int main(){
    // Given an integer n, return the least number of perfect square numbers that sum to n.

    // A perfect square is an integer that is the square of an integer; 
    // it is the product of some integer with itself. 
    // For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

    

    // Example 1:

    // Input: n = 12
    // Output: 3
    // Explanation: 12 = 4 + 4 + 4.
    int n=12;
    cout<<"no of perfect square numbers req to make "<<n<<" is "<<numSquare(n)<<endl;

    //solving  using dp
    //step 1: create a dp
    vector<int>dp(n+1,-1);
    cout<<numSquare_TOPDOWN(n,dp)<<endl;

    cout<<numSquare_BOTTOMUP(n)<<endl;

}