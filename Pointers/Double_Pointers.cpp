#include <iostream>
using namespace std;
void solve(int** ptr) {

  // copy double pointer ptr(int**ptr=c) which points to same address as c
  // c and ptr are the two diff double pointers pointing to a pointer b which is pointing to a 
  //1.ptr = ptr + 1;->will change the adrress storefd in ptr(address of b)->ptr will no longer point to b

  //2.*ptr = *ptr + 1;->changes the value stored at location b so b will no longer store the address of a as it has been changed 

  **ptr = **ptr + 1;//->changes the value stored at a
}

int main() {
  //1.DOuble Pointers->
    int a = 5;
    int* p = &a;//-> p is pointer to a
    int** q = &p;// q is pointer to the pointer p
    cout<<"address and value  of a:"<<endl;    
    cout << &a << endl;
    cout << a << endl;
    cout<<"p is pointer to a->:"<<endl;
    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl;
    cout<<"q is pointer to pointer p"<<endl;
    cout << q << endl;
    cout << &q << endl;
    cout << *q << endl;
    cout << **q << endl;// access value of a via double pointer


    //2.PASSING double pointer in Fxn
    cout<<"PASSING double pointer in Fxn"<<endl;

    int x = 12;
    int* b = &x;
    int** c = &b;
    solve(c);

    cout << x << endl;


  return 0;
}