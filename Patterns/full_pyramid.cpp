#include<iostream>
using namespace std;
void pyramid(int rows){
    for(int i=0;i<rows;i++){
        //spaces
        for(int j=0;j<rows-i;j++){
            cout<<" ";
        }
        //stars
        for(int k=0;k<2*i+1;k++){
            cout<<"*";
        }
        cout<<endl;
      
    }
}
int main(){
    pyramid(6);
}
