#include<iostream>
using  namespace std;
void inverted_hollow_half(int n){
    for(int i=0;i<n;i++){
        int start =n;
        for(int j=0;j<n-i;j++){
            //nums
            if(i==0){
                cout<<j+1;
            }
            else if(j==0){
                cout<<i+1;
            }
            else if(j==n-i-1){
                cout<<n;
                
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

}
int main(){
    inverted_hollow_half(5);
}