#include<iostream>
#include<vector>

using namespace std;
    string makeFancyString(string s) {
        if(s.length()==1){
            return s;
        }
        int freq=1;
        string ans="";
        ans.push_back(s[0]);
        for(int i=1;i<s.length();i++){
            if(s[i]==ans.back()){
                freq++;
                if(freq < 3){
                    ans.push_back(s[i]);
                }
            }
            else{
                ans.push_back(s[i]);
                //reset freq
                freq=1;
            }

        }
        return ans;

        
    }

int main(){

}