#include<iostream>
using namespace std;
void hollow_pyramid(int rows){
  for(int i=0;i<rows;i++){
    //spaces
    for(int j=0;j<rows-i-1;j++){
        cout<<" ";
    }
    //stars+space pattern
    for(int k=0;k<2*i+1;k++){
        if(k==0||k==2*i||i==rows-1){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
    }
    cout<<endl;
  }
    
       
      
}
   

int main(){
    hollow_pyramid(6);   
}