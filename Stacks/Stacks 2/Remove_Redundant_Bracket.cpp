#include<iostream>
#include<stack>

using namespace std;
//if bracket k beech me operator->not redundant and usefull bracket else->redundant and useless
bool isRedundant(string s){
    stack<char> st;
    bool flag=false;

    for(int i=0;i<s.length();i++){
        flag=false;
        char ch=s[i];
        //opening bracket or operator->push
        if(ch=='('||ch=='+'||ch=='-'||ch=='/'||ch=='*'){
            st.push(ch);
        }
        //ignore->a,b,c
        else if(isalpha(ch)){
            //skip
            continue;
        }
        //closing bracket
        else if(ch==')' && !st.empty()){
            //pop until opening encountered and if op present in between the set true
            while(st.top()!='('){
                char topch=st.top();
                if(topch=='+'||topch=='-'||topch=='/'||topch=='*'){
                    //set true
                    flag=true;
                    st.pop();
                    
                }
            }
            st.pop();
            
        }

        
    }
    return flag;


}

int main(){
    string s="(a+b)*c";
    cout<<isRedundant(s);

}