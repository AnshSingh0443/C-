#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class NQueue{
    int *a,*front,*rear,*next;
    int size;//size of main array
    int k;//no of queues
    int freespot;

    //inititalization
    public:
    NQueue(int _s,int _k):size(_s),k(_k),freespot(0){

        //inititally array
        a = new int[size];
        front = new int[k];
        rear = new int[k];
        next = new int[size];

        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        for(int i=0;i<size;i++){
            next[i]=i+1;
        }
        next[size-1]=-1;
         
    }
    bool push(int x,int qi){
        //1.check over flow
        if(freespot==-1){
            return false;
        }
        //2.find first free index
        int index=freespot;
        //3.update freespot
        freespot=next[index];
        //4.insert
        if(front[qi]==-1){
            // first element
            front[qi]=index;
        }
        else{
            //link new element to that qi ka rearest element
            next[rear[qi]]=index;
        }
        //5.update next
        next[index]=-1;
        //6.update rear
        rear[qi]=index;
        a[index]=x;

        return true;
   }

   int pop(int qi){
        //check underdlow
        if(front[qi]==-1){
            return -1;
        }
        //1.find index to pop
        int index=front[qi];
        //2.update front->new front->next[index]
        front[qi]=next[index];
        //3.update freespot and next
        next[index]=freespot;
        freespot=index;

        return a[index];
    }
    //destructor
    ~NQueue(){
        delete []a;
        delete []next;
        delete []front;
        delete []rear;
    }

};

int main(){
    NQueue q(2,8);

    
  

}