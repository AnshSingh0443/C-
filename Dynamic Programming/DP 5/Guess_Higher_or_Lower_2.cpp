#include<iostream>
#include<vector>
using namespace std;
int getMinToWin_Rec(int start,int end){
    // invalid range-> no need to guess
    // single element only one guess no penalty to be wrong->return 0
    if(start>=end){
        return 0;
    }

    int ans=INT_MAX;
    for(int i=start;i<=end;i++){
        // answer->for each no we guess we need the least amount of money to gaurantee that win(max)
        // two options when we guess wrong penalty + guess higher(i+1 to end) or lower(start to i-1)
        // but we need the min among all those answers which will gaurantee that win

        ans=min(ans,max(i+getMinToWin_Rec(start,i-1),i+getMinToWin_Rec(i+1,end)));
        
    }
    return ans;
}
//2.Memoization
int getMinToWin_TOPDOWN(int start,int end,vector<vector<int>>&dp){
    if(start>=end){
        return 0;
    }
    //step 2: check for answer in dp
    if(dp[start][end]!=-1){
        return dp[start][end];
    }

    int ans=INT_MAX;
    for(int i=start;i<=end;i++){
        //har ek guess k liye the maximum amount of penalty is the min amount of money req to gaurantee the win
        // un sabhi guesses  me se jiska min penalty  hoga vo answer hai 
         // two options when we guess wrong penalty + guess higher(i+1 to end) or lower(start to i-1)

        ans=min(ans,max(i+getMinToWin_TOPDOWN(start,i-1,dp),i+getMinToWin_TOPDOWN(i+1,end,dp)));
        
    }
    dp[start][end]=ans;
    return ans;

}
//3.Tabulation
int getMinToWin_BOTTOMUP(int n){
    //step 1: create a dp array
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));

    //revese flow of top down
    //start->n to 1
    for(int start=n;start>=1;start--){
        //end->1 to n
        for(int end=1;end<=n;end++){
            //handle a base case here and rest in the else part
            if(start>=end){
               continue;

            }else{
                //reaplce fxn call with dp and use loop variables accordingly
                int ans=INT_MAX;
                for(int i=start;i<=end;i++){
                    ans=min(ans,i+max(dp[start][i-1],dp[i+1][end]));
                }
                dp[start][end]=ans;


            }

        }
    }
    return dp[1][n];


}
int getMoneyAmount(int n){
    //using dp
    //step 1: create a dp array
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int ans=getMinToWin_BOTTOMUP(n);
    

    return ans;

}
int main(){

    int n=10;
    
    cout<<"min money req to  win "<<getMoneyAmount(n)<<endl;

}