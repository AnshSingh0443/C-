#include <iostream>
using namespace std;

class CirQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    CirQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data) { 

        //Queue Full
        if((front == 0 && rear == size-1)) {
            cout << "Q is fulll, cannot insert" << endl;
        }
        //single element case - > first element
        else if(front == -1) {
            front = rear = 0;
            arr[rear] = data;
        }
        //circular nature
        else if(rear == size-1 && front != 0 ) {
            rear = 0;
            arr[rear] = data;
        }
        //add one more condition in the QUEUE FULL if block->since in a circular queue rear can go at the front in case front is not 0
        //so another condition will be when rear is just before front ie rear =front-1
        else if(rear==front-1){
            cout<<"Queue is full";
        }
        //normal flow
        else{
            rear++;
            arr[rear]= data;
        } 
    }

    void pop() {
        
        
        
        
        //empty check
        if(front == -1) {
            cout << "Q is empty , cannot pop" << endl;
        }
        //single element
        else if (front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;  
        }
        //circular nature
        else if(front == size-1) {
            front = 0;
        }
        //normal flow
        else {
            front++;
        }
    }

};

int main() {
  cout << "Hello world!" << endl;
  return 0;
}