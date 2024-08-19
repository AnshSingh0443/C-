#include<iostream>
#include<vector>
#include<stack>


//https://leetcode.com/problems/simplify-path/description/

using namespace std;
    void buildans(stack<string>&st,string &ans){
        if(st.empty()){
            return;
        }
        string part=st.top();
        st.pop();
        buildans(st,ans);
        ans +=part;
    }
    string simplifyPath(string path) {
        stack<string>st;
        //using stack we will perform certain operation based on the part the path

        int i=0;
        while(i<path.size()){
            int start=i;
            int end=i+1;
            //so a part is taken from start to next slash-1
            //move end until it is one less than next slash
            while(end<path.size() && path[end]!='/'){
                end++;
            }
            //take the part
            string part=path.substr(start,end-start);
            // cout<<part<<endl;
            // //update i;
            i=end;

            if(part=="/"|| part=="/."){
                //ignore
                continue;
            }
            if(part!="/.."){
                st.push(part);
            }
            else if(!st.empty()){
                // "/.."->is used to  jump back to prev dir->pop
                st.pop();
            }
        }
        string ans=st.empty() ?"/":"";
        //reverse waht is in the satck is the ans;
        buildans(st,ans);
        return ans;
        
    }

int main(){
    string path="/.../a/../b/c/../d/./";
    cout<<"simplified path->"<<simplifyPath(path)<<endl;

}