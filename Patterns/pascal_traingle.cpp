#include<iostream>
using namespace std;
void pascal_traingle(int n){
    for(int i=1;i<=n;i++){
        int start=1;
        for(int j=1;j<=i;j++){
            cout<<start<<" ";
            start=start*((i-j) / j);
           
        }
        cout<<endl;
    }
}
int main(){
    pascal_traingle(6);
}