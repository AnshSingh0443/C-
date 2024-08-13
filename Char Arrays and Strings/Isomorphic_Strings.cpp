#include<iostream>
using namespace std;
bool isIsomorphic(string s, string t) {
    int hash[256]={0};// stores mapping of each char of 's' to each char of 't' 
    bool istmapped[256]={0};//stores if t[i] char is already mapped with s[i]
    for(int i=0;i<s.length();i++){
        //s[i] is not mapped yet and t[i] is also  not mapped already
       if(hash[s[i]]==0 && istmapped[t[i]]==0){   
            //map kr do t[i] se
            hash[s[i]]=t[i];
            //store that t[i] has been mapped to s[i]
            istmapped[t[i]]=true;
        }
    } 
    for(int i=0;i<s.length();i++){
        //now check if the mapping is done correctly
        if(char(hash[s[i]]!=t[i])){
            return false;
        }
    }
    return true;
        
}
int main(){
    //PROBLEM STATEMENT
    // Given two strings s and t, determine if they are isomorphic.
    // Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    // All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

    
    //EXAMPLE1
    // Input: s = "egg", t = "add"
    // Output: true    
    // mapping:e->a,g->d

    //EXAMPLE2
    // Input: s = "paper", t = "title"
    // Output: true
    // mapping: p->t,a->i,e->l,r->e

    //EXAMPLE3
    // Input: s = "foo", t = "bar"
    // Output: false
    // mapping f-> b but o can not be mapped to both a and r so not isomorphic
    string s="paper";
    string t="title";
    cout<<isIsomorphic(s,t);

}