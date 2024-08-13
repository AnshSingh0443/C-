#include<iostream>
using namespace std;

void numeric_full_pyramid(int n){
    for(int i=0;i<n;i++){
        //1ST half

        //spaces
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        //numbers
        int start=i+1;
        for(int k=0;k<i+1;k++){
            cout<<start;
            start=start+1;
        }

        //2ND HALF
        //reverse counting
        int start2=2*i;
        for(int j=0;j<i;j++){
            cout<<start2;
            start2=start2-1;
        }
        cout<<endl;

    }
}
int main(){
    numeric_full_pyramid(4);
    
}