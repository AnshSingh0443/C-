#include<iostream>
using namespace std;
//implementing stack using array
class Stack{
    public:
    int *arr;
    int top;//->used to access the top most element in the stack or last elem in stack
    int size;//-size here indicates the size of array and not the total no of elems in the stack 

    //creating a stack of size->size
    Stack(int size){
        arr=new int[size];
        this->size=size;
        top=-1;
    }

    //functions
    void push(int data){
        //if size-top=1 then it means that top is pointing at the last elem so no more elem can be inseretd in the stack
        if(size-top>1){
            //space available
            top++;
            arr[top]=data;
        }
        else{
            //space not available
            cout<<"Stack Overflow"<<endl;
        }

    }

    void pop(){
        if(top==-1){
            //no elem in the stack
            cout<<"Stack Underflow"<<endl;
        }else{
            //stack is not empty
            top--;
        }

    }

    int gettop(){
        if(top==-1){
            //stack is empty
            cout<<"NO elem in the stack"<<endl;
            return -1;
        }else{
            //stack is not empty
            return arr[top];
        }
    }
    //return the total no of stacks  in array
    int getsize(){
        return top+1;//+1 because array->0 indexed
    }
    
    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
};
int main(){

    Stack s(10);// stack of sizze 10 created

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //printing stack
    while(!s.isEmpty()){
        cout<<s.gettop()<<" "<<endl;
        s.pop();
    }

    cout<<endl;

    cout<<"size of stack is:"<<s.getsize();



}