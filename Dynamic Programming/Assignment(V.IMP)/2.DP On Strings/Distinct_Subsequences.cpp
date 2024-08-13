#include<iostream>
#include<vector>
using namespace std;
//brute force -> find all subsequence of s and for those equal to string t increment counter

//recursive approach->two pointer i and j on the two string s and t
// two ways when s[i]==j[i] le recursion take care of the rest of the string->i+1,j+1
//   2nd->we chose to ignore the current s[i] and recursive call for the rest of  the string->i+1,j 

int numDistinctHelper(string& s,string& t,int i,int j){
    //base case 1-> when j reaches s.size()->valid subsequence
    if(j==t.size()){
        return 1;
    }
    //base case 2-> when i reaches the end but j has not-> string could not be matched fully
    if(i==s.size()){
        return 0;
    }

    int ans=0;//to save no of valid subsequences
    if(s[i]==t[j]){
        ans+=numDistinctHelper(s,t,i+1,j+1);
    }
    //choosing to ignore s[i]->for other distindt subsequences
    ans+=numDistinctHelper(s,t,i+1,j);

    return ans;

}
int numDistinct_TOPDOWN(string s,string t,int i,int j,vector<vector<int>>dp){
    //base case 1-> when j reaches s.size()->valid subsequence
    if(j==t.size()){
        return 1;
    }
    //base case 2-> when i reaches the end but j has not-> string could not be matched fully
    if(i==s.size()){
        return 0;
    }
    //check dp for answer
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans=0;//to save no of valid subsequences
    if(s[i]==t[j]){
        ans+=numDistinctHelper(s,t,i+1,j+1);
    }
    //choosing to ignore s[i]->for other distindt subsequences
    ans+=numDistinctHelper(s,t,i+1,j);

    //save the ans in dp
    dp[i][j]=ans;

    return dp[i][j];

}
int numDistinct(string s, string t) {
    vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
    return numDistinct_TOPDOWN(s,t,0,0,dp);
}

int main(){
    // Example 1:

    // Input: s = "rabbbit", t = "rabbit"
    // Output: 3
    // Explanation:
    //  1. 1st b and 2nd b matched with t,
    //  2.1st b ignored and 2nd and 3rd b matched with t,
    //  3.2nd b igonred and 1st and 3rd b matched with t
    string s="rabbbit";
    string t="rabbit";
    cout<<numDistinct(s,t);
}