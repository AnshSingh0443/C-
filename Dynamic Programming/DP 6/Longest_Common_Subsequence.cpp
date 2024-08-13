#include<iostream>
#include<vector>
using namespace std;
//1.Recursion 2 pointers
int getMaxLengthLCS_REC(string a,string b,int i,int j){
    //base cases->either of string finishes
    if(i==a.length() || j==b.length()){
        return 0;
    }
    //solve one case->curr char is same and can be included in out LCS
    int ans=0;
    if(a[i]==b[j]){
        //+1 beacuse we inclcude  the char in our LCS so length is incremented by one
        ans=1+getMaxLengthLCS_REC(a,b,i+1,j+1);
    }else{
        //when they are not the same char->cannot be include in our LCS
        ans=0+max(getMaxLengthLCS_REC(a,b,i+1,j),getMaxLengthLCS_REC(a,b,i,j+1));
    }
    
    return ans;

}

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


int longestCommonSubsquence(string text1,string text2){
    int i=0;
    int j=0;
    // return getMaxLengthLCS_REC(text1,text2,i,j);
    //using dp 
    //step1:Create a dp
    vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
    return getMaxLengthLCS_TOPDOWN(text1,text2,i,j,dp);

}
//3.Tabulation
int getMaxLengthLCS_BOTTOMUP(string a,string b){
    //step 1:create a dp array
    vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
    // reverse flow of  topdown
    //i-> a.length to 0
    for(int i=a.length()-1;i>=0;i--){
        //j->b.length to 0
        for(int j=b.length()-1;j>=0;j--){
            //replace rec calls with dp and use loop variables accordingly
            int ans=0;
            if(a[i]==b[j]){
                //+1 beacuse we inclcude  the char in our LCS so length is incremented by one
                ans=1+dp[i+1][j+1];
            }else{
                //when they are not the same char->cannot be include in our LCS
                ans=0+max(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j]=ans;


        }


    }
    //since are moving from length to 0 our final answer will be stored at dp[0][0]
    return dp[0][0];

}
//5.space optimised solution from above we can see that 
// dp[i][j] curr row is dpending upon dp[i][j+1],dp[i+1][j+1] and dp[i+1][j] ie next row
int getMaxLength_SO(string a ,string b){
    //for row we are using b
    vector<int>curr(b.length()+1,0);
    vector<int>next(b.length()+1,0);

    for(int i=a.length()-1;i>=0;i--){
        
        for(int j=b.length()-1;j>=0;j--){
            
            int ans=0;
            if(a[i]==b[j]){
                
                ans=1+next[j+1];//next->dp[i+1]
            }else{
                ans=0+max(next[j],curr[j+1]);//curr->dp[i]
            }
            curr[j]=ans;

        }
        //shift
        next=curr;

    }

    return next[0];
  

}

int main(){
    // a subsequence of a string is a new string generated from original string with some characters(can be none)
    // deleted without changing the relative order of remaning chars
    string text1="abc";
    string text2="ace";
    cout<<"LCS of length "<<longestCommonSubsquence(text1,text2)<<" possible"<<endl;

  
}