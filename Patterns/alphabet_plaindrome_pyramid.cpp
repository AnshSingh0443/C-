#include<iostream>
using namespace std;
void alphabet_palindrome_pyramid(int n){
    for (int i=0; i < n; i++){
        int j;
        for(j=0;j<i+1;j++){
            cout<<j+1;
        }
        j=j-1;
        for(;j>=1;j--){
            cout<<j;
        }
        cout<<endl; 
    }
    

}
int main(){
    alphabet_palindrome_pyramid(5);

}