#include<iostream>
using namespace std;
void  inverted__full_pyramid(int row){
    for(int i=0;i<row;i++){
        //print spaces
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        //stars
        for(int k=0;k<row-i;k++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    inverted__full_pyramid(6);

}

