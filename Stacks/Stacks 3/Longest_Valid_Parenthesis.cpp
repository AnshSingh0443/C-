#include<iostream>
#include<stack>
using namespace std;
int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int Maxlen=0;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    int len=i-st.top();
                    Maxlen=max(len,Maxlen);
                }
            }
        }

        return Maxlen;
        
}
int main(){
    string s="))()()";
    cout<<longestValidParentheses(s);

}