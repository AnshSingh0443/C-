#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class MyQueue {
public:
    //stack ->s1 and s2
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        //o(n)
            //1. all elem s1->s2
        // while(!s1.empty()){
        //     int top=s1.top();
        //     s1.pop();
        //     s2.push(top);
        // }
        //     //2.push x to s1
        // s1.push(x);

        //     //3.all elem s2->s1
        // while(!s2.empty()){
        //     int top=s2.top();
        //     s2.pop();
        //     s1.push(top);
        // }

        //o(1)-->but pop will take o(n) now
        //push x to s1
        s1.push(x);
        
    }
    
    int pop() {
        //o(1)
        // int top=s1.top();
        // s1.pop();
        // return top;

        //o(n)
        //if s2 not empty-->pop from s2
        //if empty->1.s1---s2 all and then pop  from s2

        if(!s2.empty()){
            int top=s2.top();
            s2.pop();
            return top;
        }else{
            //s1-s2
            while(!s1.empty()){
                int top=s1.top();
                s1.pop();
                s2.push(top);
            }
            //pop from s2
            int top=s2.top();
            s2.pop();
            return top;
       

        }
        
    }
    
    int peek() {
        //if s2 not empty -->return s2.top()
        if(!s2.empty()){
            return s2.top();
        }else{
            //s1-->s2
            while(!s1.empty()){
                int top=s1.top();
                s1.pop();
                s2.push(top);
            }
            return s2.top();
        }
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main(){
    
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */