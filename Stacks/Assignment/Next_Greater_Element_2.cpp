#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//for normal array
vector<int> nextGreaterElements(vector<int>& v) {
    stack<int> st;
    st.push(-1);

    vector<int>ans(v.size(),-1);

    

    for(int i=v.size()-1;i>=0;i--){
        int curr=v[i];


        while(!st.empty() && st.top()<=curr){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(curr);
    }
    return ans;

}

//next gratear for circular array
vector<int> nextGreaterElements2(vector<int>& v) {
    stack<int> st;
    st.push(-1);

    vector<int>ans(v.size(),-1);

    

    for(int i=2*(v.size())-1;i>=0;i--){
        int curr=v[i%v.size()];


        while(!st.empty() && st.top()<=curr){
            st.pop();
        }
        if(st.empty()){
            ans[i%v.size()]=-1;
        }
        else{
            ans[i%v.size()]=st.top();
        }
        st.push(curr);
    }
    return ans;

}

int main(){
    vector<int>v={3,10,4,2,1,2,6,1,7,2,9};
    vector<int>res=nextGreaterElements2(v);

    for(auto i:res){
        cout<<i<<" ";
    }


}