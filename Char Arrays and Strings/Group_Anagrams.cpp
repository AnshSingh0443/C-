#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//USING SORT
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string,vector<string>>mp;
    for(auto str:strs){
        string s= str;
        sort(s.begin(),s.end());
        mp[s].push_back(str);
        //using sorted str(s) as key we push str(its anagram) as its value
    }
    //iterate on the map
    vector<vector<string>>ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        ans.push_back(it->second);
        //push it->second that is value(vector of strings anagram) corresponding to key(sorted str)
    }
    return ans;
     
}


//hash function
std::array<int,256> hashing(string s){
    std::array<int,256>hash={0};
    for(int i=0;i<s.length();i++){
        hash[s[i]]++;
    }
    return hash;

}
vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    map< std::array<int,256>, vector<string> >mp;
    for(auto str:strs){
        mp[hashing(str)].push_back(str);
    }

    vector<vector<string>> ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        ans.push_back(it->second);
    }
    return ans;
     
}

int main(){
    //PROBLEM STATEMENT
    // Given an array of strings strs, group the anagrams together. You can return the answer in any order.
    // An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
    //  typically using all the original letters exactly once.

 
    //EXAMPLES
    // Example 1:
    // Input: strs = ["eat","tea","tan","ate","nat","bat"]
    // Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    // Example 2:
    // Input: strs = [""]
    // Output: [[""]]

    // Example 3:
    // Input: strs = ["a"]
    // Output: [["a"]]
    vector<string>strs{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>res=groupAnagrams(strs);

    
}