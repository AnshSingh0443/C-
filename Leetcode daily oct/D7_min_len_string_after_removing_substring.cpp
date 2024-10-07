#include<iostream>
#include<vector>
#include<stack>

using namespace std;
    //BRUTE FORCE->loop until AB OR CD eisits
    int minLengthBRUTE_FORCE(string s) {
        //so since we can keep remobving AB and CD until we cannot
        // we get the min length string return this length

        //base case if there is no AB and CD in the string return s.length()

        if(s.find("AB")==string::npos && s.find("CD")==string::npos){
            //both AB and CD not in string
            return s.length();
        }

        while(s.find("AB")!=-1 || s.find("CD")!=-1){
            //remove ab 
            if(s.find("AB")!=-1){
                //remove all occ of AB
                s.erase(s.find("AB"),2);
            }
            //remove cd
            else if(s.find("CD")!=-1){
                //remove all occ of cd
                s.erase(s.find("CD"),2);
            }

        }


        return s.length();
        
    }
    //Better approach->Using Stack
    int minLength(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){
            //each char in s
            char ch=s[i];
            //initially when stack is empty
            if(st.empty()){
                st.push(ch);
                continue;
            }
            if(!st.empty()){
                //check for pattern
                if(ch=='B' && st.top()=='A'){
                    //AB pattern 
                    st.pop();
                }
                else if(ch=='D' && st.top()=='C'){
                    //CD pattern
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
            
        }
        return st.size();
    }
int main(){

}