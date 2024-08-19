#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/

    bool isValid(string s) {
        //RECURSIVE SOLN->TLE
        //base case
    //     if(s.size()==0){
    //         return true;
    //     }
    //     //step 1->find abc 
    //     int pos=s.find("abc");
    //     if(pos!=string::npos){
    //         //found
    //         //abc hai
    //         //find t left and t right
    //         string tleft=s.substr(0,pos);
    //         cout<<tleft<<endl;
    //         string tright=s.substr(pos+3,s.size());
    //         cout<<tright<<endl;
    //         //rec call
    //         return isValid(tleft+tright);

    //     }


    //    return false;
        
        //STACK SOLN
        if(s[0]!='a'){
            return false;
        }
        stack<char>st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='a'){
                st.push(s[i]);
            }
            else if(s[i]=='b' && !st.empty() && st.top()=='a' ){
                st.push(s[i]);
            }
            else if(s[i]=='b' &&   !st.empty() && st.top()!='a'){
                return false;
            }
            else if(s[i]=='c' && !st.empty() &&st.top()=='b' ){
                // one pair of abc is popped
                st.pop();
                st.pop();
            }
            else{
                return false;
            }
            i++;
        }
        if(st.empty()){
            return true;
        }
        else
            return false;

        
    }


int main(){

}