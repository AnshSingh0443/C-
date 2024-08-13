#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int start=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*i+1;j++){
            if(j==0||j%2==0){
                cout<<start;
               start=start+1;
            }else{
                cout<<"*";
            }
            
            
        }
        cout<<endl;
    }
    //reverse
    int start2=start-n;
    for(int i=0;i<n;i++){
        int k=start2;
        for(int j=0;j<2*n-2*i-1;j++){
            if(j==0||j%2==0){
                cout<<k;
                k++;
               
            }else{
                cout<<"*";
            }
           
        }
        start2=start2-(n-i-1);
        cout<<endl;
    }


}