#include<iostream>
#include<vector>
using namespace std;
    bool check(string& word,vector<string>& wordDict){
        for(auto i:wordDict){
            if(word==i){
                //word is present in the dict
                return true;
            }
        }
        return false;
    }
    //1.Recursion
    bool solve(string s, vector<string>& wordDict,int start){
        //base case-> we reach the end of the string
        if(start==s.length()){
            return true;
        }
        //solve one case
        string word="";
        bool flag=false;
        for(int i=start;i<s.length();i++){
            word=word+s[i];
            //check if word is present in the dict
            //call for rest of the string
            if(check(word,wordDict)){
                flag = flag ||solve(s,wordDict,i+1);
            }

        }
        return flag;
    }

    //2.Memoization->topdown
    bool Solve_TOPDOWN(string s, vector<string>& wordDict,int start,vector<int>&dp){
        //base case-> we reach the end of the string
        if(start==s.length()){
            return true;
        }

        //check in dp
        if(dp[start]!=-1){
            return dp[start];
        }
        //solve one case
        string word="";
        bool flag=false;
        for(int i=start;i<s.length();i++){
            word=word+s[i];
            //check if word is present in the dict
            //call for rest of the string
            if(check(word,wordDict)){
                flag = flag ||Solve_TOPDOWN(s,wordDict,i+1,dp);
            }

        }
        dp[start]=flag;
        return dp[start];

    }
    //3.tabulation->BottomUP
    bool Solve_BOTTOMUP(string s, vector<string>& wordDict){
        //create dp
        vector<int>dp(s.length(),0);
        //base case
        dp[s.length()]=true;

        //reverse flow of top down 
        for(int start=s.length()-1;start>=0;start--){

            string word="";
            bool flag=false;
            for(int i=start;i<s.length();i++){
                word=word+s[i];
                //check if word is present in the dict
                //call for rest of the string
                if(check(word,wordDict)){
                    flag = flag || dp[i+1];
                }

            }
           dp[start]=flag;

        }

        return dp[0];

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // return solve(s,wordDict,0); recursion used

        //step 1 create a dp
        vector<int>dp(s.length(),-1);
        return Solve_TOPDOWN(s,wordDict,0,dp);
        
    }
int main(){

}