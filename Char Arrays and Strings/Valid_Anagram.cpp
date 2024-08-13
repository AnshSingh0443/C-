#include<iostream>
#include<algorithm>
using namespace std;
//METHOD 1- sort the 2 string and then compare if they are the same if yes then true, if not then false-o(nlogn)
bool isAnagram1(string s, string t) {
    if(s.length()!=t.length()){
        return false;
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if(s==t){
        return true;
    }
    return false;
        
}

//METHOD 2-creating a frequency table with length=256(last ASCII value )
//here we will take chars as index and there count as  freqtable[i] we will increament for each char in s string 
// and decrement for each char in t string if the table results in all zeros  then s and t are anagarms
bool isAnagram2(string s, string t) {
    if(s.length()!=t.length()){
        return false;
    }
    int freqtable[256]={0};
    for(int i=0;i<s.length();i++){
        freqtable[s[i]]++;//increment for each char of s
        //eg s[0]=a and a='96' so at index 96 value will be incremented by 1
    }   
    for(int i=0;i<t.length();i++){
        freqtable[t[i]]--;//decrement for each char of t
        //eg s[0]=a and a='96' so at index 96 value will be incremented by 1 and if anagaram then eventually making it back to 0
    }
    for(int i=0;i<256;i++){
        if(freqtable[i]!=0){
            return false;
        }
        return true;

    }


        
}

int main(){
    //PROBLEM STATEMENT
    // Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    // An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
    // typically using all the original letters exactly once.

    //EXAMPLE
    // Input: s = "anagram", t = "nagaram"
    // Output: true

    string s="anagram";
    string t="nagaram";
    cout<<isAnagram1(s,t);
    cout<<isAnagram2(s,t);


   
   
}