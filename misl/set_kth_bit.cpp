#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the value:";
    int n;
    cin>>n;
    cout<<endl<<"enter the value of k:";
    int k;
    cin>>k;

    int mask=1 << k;
    int ans=n|mask;//bitwise or 
    cout<<ans;


}