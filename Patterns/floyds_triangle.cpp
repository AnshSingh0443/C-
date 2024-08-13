#include<iostream>
using namespace  std;
void floyds_traingle(int n){
    int start=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*i+1;j++){
            if(j==0||j%2==0){
                cout<<start;
                start=start+1;
            }else{
                cout<<" ";
            }
           

        }
        cout<<endl;
    }
}
int main(){
    floyds_traingle(10);
    
}