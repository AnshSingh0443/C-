#include<iostream>
using namespace std;

    //function to check if string is a plaindrome
    bool checkplaindrome(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                // ya toh s[i] ko remove kar k plaindrome ban sakta hai ya fir s[j] ko
                return checkplaindrome(s,i+1,j) || checkplaindrome(s,i,j-1);
                // when i is removed we check from i+1
                // when j is removed we check from j-1
            }
            else{
                // s[i]==s[j]
                i++;
                j--;
            }
        }
        return true;
            
    }
int main(){
    //PROBLEM STATEMENT
    // Given a string s, return true if the s can be palindrome after deleting at most one character from it.


    //EXAMPLE
    // Input: s = "abca"
    // Output: true
    // Explanation: You could delete the character 'c'.
    string s="abca";
    cout<<validPalindrome(s);
}