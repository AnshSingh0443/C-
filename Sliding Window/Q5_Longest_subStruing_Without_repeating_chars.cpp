#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<set>

using namespace std;

    int lengthOfLongestSubstring(string s) {
        //varible sliding window
        int i=0;
        int j=0;
        int len=0;
        set<char>st;

        while(j<s.length()){
            if(st.find(s[j])==st.end()){
                //current char is not in in the set
                st.insert(s[j]);
                //update len
                len=max(len,j-i+1);
                j++;
            }else{
                //curr char already in set->duplicate minimize window
                //remove and i++
                st.erase(s[i]);
                i++;
            }
        
            
        }
        return len;
        
    }

int main(){
    string s="abcabcbb";

    cout<<lengthOfLongestSubstring(s);
}