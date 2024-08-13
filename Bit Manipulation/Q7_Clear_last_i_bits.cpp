#include<iostream>
using namespace std;

int main(){
    int n=7;
    int i=2;
    int mask=-1<<i;
    n=n&mask;
    cout<<n;

}