#include<iostream>
#include<vector>
using namespace std;
    //BRUTE FORCE
    bool isPalindrome(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int maxlength=1;
    int start=0;
    //recursive function to check is string i to j is a palindrome
    bool Solve(int i,int j,string& s,vector<vector<int>>&dp){
        //base case
        if(i>=j){
            return true;
        }
        //check
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool flag=false;
        if(s[i]==s[j]){
            flag=Solve(i+1,j-1,s,dp);
        }
        if(flag){
            //string is  a palindrome
            int currlength=j-i+1;
            if(currlength>maxlength){
                maxlength=currlength;
                start=i;
            }
        }
        //update
        return  dp[i][j]=flag;
    }

    string longestPalindrome(string s){
        //BRUTE FORCE
        // string ans="";
        // for(int i=0;i<s.length();i++){
        //     for(int j=i;j<s.length();j++){
        //         if(isPalindrome(s,i,j)){
        //             string t=s.substr(i,j-i+1);
        //             ans=t.size()>ans.size() ? t:ans;
        //         }
        //     }
        // }
        // return ans;

        //step 1 genterating  substrings

        int n=s.size();
        //create dp
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                bool t=Solve(i,j,s,dp);
            }
        }

        return s.substr(start,maxlength);
            
    }
int main(){
    string s="abcbadab";
    cout<<longestPalindrome(s);
    

}