#include<iostream>
using namespace std;
void butterfly(int n){
    //part1-upper half
    for(int i=0;i<n;i++){
        //star
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        //spaces
        for(int k=0;k<n-i;k++){
            cout<<" ";
        }
        //spaces
        for(int l=0;l<n-i-1;l++){
            cout<<" ";
        }
        for(int m=0;m<i+1;m++){
            cout<<"*";
        }
        cout<<endl;
    }
    //part2=lower half
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        //spaces
        for(int k=0;k<i+1;k++){
            cout<<" ";
        }
        //spaces
        for(int l=0;l<i;l++){
            cout<<" ";
        }
        for(int m=0;m<n-i;m++){
            cout<<"*";
        }
        cout<<endl;

    }
}
int main(){
    butterfly(5);
    
}