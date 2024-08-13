#include<iostream>
using namespace std;
void numeric_half_pyramid(int row){
    for(int i=1;i<=row;i++){
        for(int j=1;j<i+1;j++){
            cout<<j;
        }cout<<endl;
    }
    
}
void numeric_inverted(int row){
    for(int i=0;i<row;i++){
        for(int j=0;j<row-i;j++){
            cout<<j+1;
        }cout<<endl;
    }
}
int main(){
    numeric_half_pyramid(5);
    numeric_inverted(5);
}