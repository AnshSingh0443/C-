#include<iostream>
using namespace std;
int ExpandAroundIndex(string s,int i,int j){
    int count=0;
    while(i>=0 && j<s.length() && s[i]==s[j]){
        count++;
        i--;
        j++;
    }
    return count;
}
int countSubstrings(string s) {
    int count=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        //odd->i and j 
        int oddkaAns=ExpandAroundIndex(s,i,i);
        count=count+oddkaAns;


        //even
        int evenkaAns=ExpandAroundIndex(s,i,i+1);
        count=count+evenkaAns;
    }
    return count;
}
int main(){
    // PROBLEM STATEMENT:->
    // Given a string s, return the number of palindromic substrings in it.
    // A string is a palindrome when it reads the same backward as forward.
    // A substring is a contiguous sequence of characters within the string.

    // EXAMPLE:->
    // string s="noon"
    // 1.all substrings are:n,no,noo,noon,
    //                     o,oo,oon,o
    //                     o,on
    //                     ,n
    // 2.Palindromic substrings are:n,o,oo,noon count=4


    // METHOD 1->find all substring0(n^2) then chech if each substring is palindrome or not while  keeping count(n)-o(n^3)

    //METHOD 2->handling substring with odd and even length seperately 
    //Two pointers
    string s="noon";
    cout<<"the no of palindromic substrings are "<<countSubstrings(s);
}