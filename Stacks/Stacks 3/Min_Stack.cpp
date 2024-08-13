#include<iostream>
#include<vector>
using namespace std;
class MinStack {
public:
    vector<pair<int,int>> st;

    MinStack() {
    
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int,int> p=make_pair(val,val);
            st.push_back(p);
        }
        else{
            pair<int,int>p;
            p.first=val;
            p.second=min(val,st.back().second);
            st.push_back(p);
        }
        
    }
    
    void pop() {
        st.pop_back();
        
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(){
    MinStack*obj=new  MinStack();
    obj->push(10);
    obj->push(20);
    obj->push(3);
    obj->push(30);
    obj->push(40);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();

    cout<<param_3<<endl;
    cout<<param_4;// min in the stack
}
