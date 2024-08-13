#include<iostream>
using namespace std;
void numeric_hollow_pyramid(int n){
    for(int i=0;i<n;i++){
        //spaces
        for(int j=0;j<n-i-1;j++){
            cout<<" ";    
        }
        //nums
        int start=2;
        for(int k=0;k<2*i+1;k++){
            
            if(k==0){
                cout<<1;
            }
            
            else if(i==n-1){
                
                if(k%2==0){
                    cout<<start;
                    start=start+1;
                }
                else{
                    cout<<" ";
                }
            }
            else if(k==2*i){
                cout<<i+1;
            }
            else{
                cout<<" ";
            }

        }
        cout<<endl;
    }
}
int main(){
    numeric_hollow_pyramid(5);
    
}