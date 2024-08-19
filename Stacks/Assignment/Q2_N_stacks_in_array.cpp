#include<iostream>

using namespace std;

class Nstack{
    int *a,*top,*next;
    int n;//no of stacks
    int size;//size of main array
    int freespot;

    public:
        //initialize n with _n and size with _s
        Nstack(int _n,int _s):n(_n),size(_s){
            freespot=0;
            a=new int[size];
            top=new int[n];// to store top of ith stack
            next=new int[size];// 1. to can point to next element in stack after top ,2. can point to next freespace

            //inititalization
            for(int i=0;i<n;i++){
                top[i]=-1;
            }

            for(int i=0;i<size;i++){
                next[i]=i+1;
            }
            next[size-1]=-1;

            
        }

        bool push(int x,int m){
            //x->element to push and m->which stack to push s1,s2,.....
            if(freespot==-1){
                return false;//stack overflow
            }

            //1.find index
            int index=freespot;

            //2.update freespot
            freespot=next[index];

            //3.insert
            a[index]=x;

            //4.update next
            next[index]=top[m-1];

            //5.update top
            top[m-1]=index;

            return true;
        }

        int pop(int m){
            //m->konse satck se pop karna hai
            if(top[m-1]==-1){
                return -1;//stack is empty
            }
            //1.find index
            int index=top[m-1];
            //2.update top
            top[m-1]=next[index];
            //3.pop elemrnt
            int popelem=a[index];
            //4.update next
            next[index]=freespot;
            //5.update freespot
            freespot=index;
            return  popelem;
        }

        ~Nstack(){
            delete []a;
            delete []top;
            delete []next;
        }
};


int main(){
    Nstack s(3,6);
    cout<<s.push(10,1);
    cout<<s.push(10,1);
    cout<<s.push(10,1);
    cout<<s.push(10,1);
    cout<<s.push(10,1);
    cout<<s.push(10,1);
    cout<<s.push(10,1);//0 beacuse size is 6 only
    cout<<endl;
    cout<<s.pop(1);//10

    return 0;
}