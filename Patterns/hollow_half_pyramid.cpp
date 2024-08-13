#include<iostream>
using namespace std;

void inverted_hollow_pyramid(int rows){
    for(int i=0;i<rows;i++){
        //print stars
        for(int j=0;j<rows-i;j++){
            if(i==0||j==0||j==rows-1-i){
                cout<<"*";;
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

}

int main(){
    inverted_hollow_pyramid(7);
}