#include<iostream>
using namespace std;
string removeDuplicates(string s) {
    string ans="";
    int i=0;
    while(i<s.length()){
        if(ans.length()>0){
            //if the last char of the array is same as the string char then-(ADJACENT Duplicate) remove from ans
            if(ans[ans.length()-1]==s[i]){
                ans.pop_back();
            }
            //if not then add it to the ans
            else{
                ans.push_back(s[i]);
            }     
        }
        //push first char in the ans
        else{
            ans.push_back(s[i]);
        }
        i++;
    }
    return ans;
        
}
int main(){
    // Example:->
    // Input: s = "abbaca"
    // Output: "ca"
    // Explanation: 
    // For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal,
    // and this is the only possible move. 
    // The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

    string s="abbaca";
    string res=removeDuplicates(s);
    cout<<res;
    

}