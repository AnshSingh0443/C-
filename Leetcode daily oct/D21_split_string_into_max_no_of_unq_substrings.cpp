#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>

using namespace std;
    void solve(string &s,int i, unordered_set<string>&st,int currCount,int& maxCount){
        //puring -> no need for further calls to find maxcount as it will still be lower or equal to the maxcount
        if(currCount + (s.length()-i) <= maxCount){
           return;
        }
        if(i>=s.length()){
            maxCount=max(maxCount,currCount);
            return;
        }
        //create substring using j pointer and backtrack to find max
        for(int j=i;j<s.length();j++){
            string sub=s.substr(i,j-i+1);
            if(st.find(sub)==st.end()){
                //not in set
                //insert
                st.insert(sub);
                //fnx call
                solve(s,j+1,st,currCount+1,maxCount);
                //backtrack
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        // RECURSION AND BACKTRACKING 
        unordered_set<string>st;
        int i=0;
        int currCount=0;
        int maxCount=0;
        solve(s,i,st,currCount,maxCount);
        return maxCount;
    }

int main(){

}