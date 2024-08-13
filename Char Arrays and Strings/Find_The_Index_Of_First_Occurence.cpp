#include<iostream>
using namespace std;
//T.C-o(n*m)
int strStr(string haystack, string needle) {
    int n=haystack.length();
    int m=needle.length();
    // i->iterate over haystack
    // j->iterate over needle
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<m;j++){
            if(needle[j]!=haystack[i+j]){
                //why i+j-> beacuse i will be at fixed pos only in the loop
                //so to compare the whole string we do i+j
                break;//if the string does not match we break out of the loop
            }
            if(j==m-1){
                // j reached the end of the string meaning we found the string in haystack
                return i;//we return i which indicates the starting of the string to be found
            }
        }

    }
    return -1;

}
int main(){

    //PROBLEM STATEMENT
    // Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
    // or -1 if needle is not part of haystack.

 
    //EXAMPLES
    // Example 1:
    // Input: haystack = "sadbutsad", needle = "sad"
    // Output: 0
    // Explanation: "sad" occurs at index 0 and 6.
    // The first occurrence is at index 0, so we return 0.

    // Example 2:
    // Input: haystack = "leetcode", needle = "leeto"
    // Output: -1
    // Explanation: "leeto" did not occur in "leetcode", so we return -1.
    string haystack="leetcode";
    string needle="sad";
    cout<<strStr(haystack,needle);
}