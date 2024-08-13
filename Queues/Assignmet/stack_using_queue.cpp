#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
class MyStack {
public:
    //using single queue
    queue<int>q;
    
    MyStack() {
        
    }
 
    
    void push(int x) {
        //1.push element into queue
        q.push(x);
        //2.loop chalu size-1 and rest of the elem ko pop kro then push-->jo first the ab last---->FIF0->LIFO(satck)
        for(int i=0;i<q.size()-1;i++){
            int front=q.front();
            q.pop();
            q.push(front);
        }
    }
    
    int pop() {
        int top=q.front();
        q.pop();
        return top;
        
    }
    
    int top() {
        //front-->gives top of the queue
        return q.front();
        
    }
    
    bool empty() {
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main(){

} 
