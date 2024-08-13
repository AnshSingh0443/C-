#include<iostream>
#include<vector>
using namespace std;
//2.Memoization
int getMaxLengthLCS_TOPDOWN(string a,string b,int i,int j,vector<vector<int>>&dp){
    //base cases->either of string finishes
    if(i==a.length() || j==b.length()){
        return 0;
    }
    //step 2:check for ans in dp
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //solve one case->curr char is same and can be included in out LCS
    int ans=0;
    if(a[i]==b[j]){
        //+1 beacuse we inclcude  the char in our LCS so length is incremented by one
        ans=1+getMaxLengthLCS_TOPDOWN(a,b,i+1,j+1,dp);
    }else{
        //when they are not the same char->cannot be include in our LCS
        ans=0+max(getMaxLengthLCS_TOPDOWN(a,b,i+1,j,dp),getMaxLengthLCS_TOPDOWN(a,b,i,j+1,dp));
    }
    dp[i][j]=ans;
    
    return dp[i][j];

}
int LPS(string s){

}
int main(){
    //approach 1->
    //input string->s1
    //revese of input string->s2
    //running  longest common subsequence for s1 and s2 will give the longest palindromic subsequence 
    
   

}