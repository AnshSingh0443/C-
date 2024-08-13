#include<iostream>
using namespace std;
int main(){
    int a=5;
    // &->addressof operator
    cout<<"address of a is:"<<&a<<endl;

    //Pointer creation
    int*p=&a;
    //int *p-> p is a pointer to integer data
    //here p stores the address of variable a
    //POINTER is a special  varibale that stores the address of other variables

    cout<<"address stored in p is:"<<p<<endl;
    
    //*p->dereferencing operator
    cout<<"p is pointing to the value:"<<*p<<endl;
    //here *p->acess the value which is stored at address which P is pointing To
    //or acess the value at location stored in p

    //we can acesss the adress of pointer by simply using addressOf operator
    cout<<"address of pointer is:"<<&p<<endl;

    //size of pointer is dependent upon system architecture(64bit or 32 bit) and 
    //and does not depent on the type of data(int,char,double....) it is pointing to
    cout<<"size of pointer p is:"<<sizeof(p)<<endl;


    // //BAD Practice
    // int*ptr;//->this points to garbage value



    // //Instead we do this
    // //NULL POINTER
    // int *ptr=0;
    // //Mordern c++
    // int *ptr=nullptr;



    //COPY pointer
    int b=10;
    int *q=&b;
    int *dusraptr=q;
    //ponter->q and dusraptr both are pointing to same variable b
    cout<<*q<<*dusraptr<<endl;

    //EXAMPLE
    
    int a = 10;
    int* p = &a;
    int* q = p;
    int* r = q;

    cout << a << endl; //10
    cout << &a << endl; //address of a 
    cout << p << endl; //address of a 
    cout << &p << endl; //address of p
    cout << *p << endl; //10
    cout << q << endl; //address of a
    cout << &q << endl; //address of q
    cout << *q << endl; //10
    cout << r << endl; //address of a
    cout << &r << endl; //address of r
    cout << *r << endl; //10
    cout << (*p + *q + *r) << endl; //30
    cout << (*p)*2 + (*r)*3 << endl; //50
    cout << (*p/2) - (*q)/2 << endl; //0



}