#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
    string decodeString(string s) {
        stack<string>st;
       for(auto ch:s){    
            if(ch==']'){
                //closing bracket->mil gaya
                //pop till we get a numeric value and for string value keep adding it
                string stringToRepeat="";
                while(!st.empty() && !isdigit(st.top()[0])){
                    string top=st.top();
                    stringToRepeat+=top=="[" ? "":top;//agar top is opening bracket->do not add to string
                    st.pop();
                    //chars to add kar rahe hai  until ek numeric value nahi milte
                }
                //we st.top()->numeric value hai
                string numericTimes="";
                while(!st.empty() && isdigit(st.top()[0])){
                    //keep adding until numeric hai
                    numericTimes+=st.top();
                    st.pop();
                }
                //numeric->string me hai and reversed hai
                //actual numeric->reverse->int
                reverse(numericTimes.begin(),numericTimes.end());
                //convert string to int
                int n=stoi(numericTimes);

                //process / deecode karo
                //n times stringToRepeat ko repeat kro and push to stack
                string decode="";
                while(n--){
                    decode+=stringToRepeat;
                }

                st.push(decode);

            }else{
                //char to string
                string temp(1,ch);
                st.push(temp);
            }
       }

        //finally stack me ab decode string hai but in reverse
        string ans="";
        while(!st.empty()){
            string temp=st.top();
            ans+=temp;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }

int main(){
    string s="2[abc]3[cd]ef";

    cout<<decodeString(s);

}