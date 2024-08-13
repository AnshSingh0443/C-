#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
    string minWindow(string s, string t) {
        //base case
        if(s.length() < t.length()){
            return "";
        }
        //create a freq map

        unordered_map<char,int>freq;
        for(int i=0;i<t.size();i++){
            freq[t[i]]++;
        }
        int j=0;
        int i=0;
        int start=0;
        int len=INT_MAX;
        int counter=t.size();

        while(j<s.size()){
            char ch=s[j];
            //if ch exists in t->decrease counter
            if(freq[ch]>0){
                counter--;
            }
            //decrease freq 
            freq[ch]--;
            //move j
            j++;

            //valid window found->try to minimize
            while(counter==0){
                char startchar=s[i];
                //update start and length
                if(j-i<len){
                    start=i;
                    len=j-i;
                }
                //freq of s[i]++
                freq[startchar]++;

                //if this startchar exisits in freq->increment counter
                if(freq[startchar]>0){
                    counter++;
                }

                //move i
                i++;
            }
        }
        if(len!=INT_MAX){
            //return substring starting with start and length=len
            return s.substr(start,len);
        }else
            return "";
        
    }

int main(){
    // Input: s = "ADOBECODEBANC", t = "ABC"
    // Output: "BANC"
    // Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<minWindow(s,t);

}