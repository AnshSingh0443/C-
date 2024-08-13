#include<iostream>
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

string longestPalindrome(string s){
    string  ans="";
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            if(isPalindrome(s,i,j)){
                string t=s.substr(i,j-i+1);
                if(ans.size()<t.size()){
                    ans=t;
                }
            }
        }
    }
    return ans;
        
}

int main(){
    //EXAMPLE
    // Input: s = "babad"
    // Output: "bab"
    // Explanation: "aba" is also a valid answer
    string s="babad";
    cout<<longestPalindrome(s);


}