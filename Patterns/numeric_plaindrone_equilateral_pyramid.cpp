#include<iostream>
using namespace std;
void equilateral(int n){
    //part1
    for(int i=0;i<n;i++){
        //spaces
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        //pattern
        int start=2;
        for(int k=0;k<i+1;k++){
           if(k==0){
            cout<<1;
           }
           else{
            cout<<start;
            start=start+1;
           }
            
        }
       
       
        //pattern
        int start2=i;
        for(int j=0;j<i;j++){
            cout<<start2;
            start2=start2-1;
        }
        cout<<endl;
    }
}
int main(){
    equilateral(5);
}