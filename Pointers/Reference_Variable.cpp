#include <iostream>
using namespace std;
// void solve(int& num ) {
//         num  = 50;
// } 

// void solve(int* val) {
//         *val = *val + 1;
// }

// void solve(int*& p) {
//         p = p + 1;
// }



int main() {
    int a = 5;
    //creating a reference variable-> we can access the same memory location using diff names
    int& b = a;
    //b-> is a reference variable pointing to the same memory location of 'a'

    cout << a << endl;
    cout << b << endl;

    //since they are pointing to same memory location-> value at the location cab be changed using both a and b
    //1.change using a  
    a++;
    cout << a << endl;
    cout << b << endl;
    //2.change using reference variable b
    b++;
    cout << a << endl;
    cout << b << endl;



    //PASS BY REFERENCE:->
    //1.Normal varibale
    // int a = 5;
    // solve(a) ;
    // cout << a << endl;
 
    //2.Pointer->pass by value
    // int a = 12;
    // int *p = &a;
    // solve(p);
    // cout << a << endl;

    //3.Pointer->pass by reference
    // int a = 5;
    // int* p = &a;
    // cout << "before " << p << endl; 
    // solve(p);
    // cout << "After " << p << endl;
    

  return 0;
}