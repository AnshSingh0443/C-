#include<iostream>
#include<vector>

using namespace std;
    //freq check
    bool areFreqEqual(vector<int>freq1,vector<int>freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
 
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        vector<int>freq1(26,0);

        for(int i=0;i<s1.length();i++){
            char ch=s1[i]-'a';
            freq1[ch]++;
        }
        vector<int>freq2(26,0);// to store freq of char
        int i=0;
        int j=0;

        while(j<s2.length()){
            char ch=s2[j]-'a';
            freq2[ch]++;

            //check if window  length is s1.length
            if(j-i+1 == s1.length()){
                //possible ans
                //check freq
                //if freq of chars in 1 is equal to 2->permutaion found
                if(areFreqEqual(freq1,freq2)){
                    return true;
                }
            }
            if(j-i+1<s1.length()){
                j++;
            }else{
                char ch=s2[i]-'a';
                freq2[ch]--;
                i++;
                j++;
            }
        }
        return false;
    }

int main(){
    //In other words, return true if one of s1's permutations is the substring of s2.
    // Input: s1 = "ab", s2 = "eidbaooo"
    // Output: true
    // Explanation: s2 contains one permutation of s1 ("ba").
    cout<<checkInclusion("ab","eidbaooo");
}