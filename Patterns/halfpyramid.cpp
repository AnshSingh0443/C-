#include<iostream>
using namespace std;
void half_pyramid(int row){
    for(int i=0;i<row;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
        
    }
}
int main(){
    half_pyramid(9);

}