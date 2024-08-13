#include<iostream>
using namespace std;
void diamond(int rows){
    for(int i=0;i<rows;i++){
        //1ST HALF        
        //spaces
        for(int j=0;j<rows-i-1;j++){
            cout<<" ";
        }
        //starts pattern
        for(int k=0;k<(2*i)+1;k++){
            //1st char-star
            if(k==0){
                cout<<"*";
            }
            //last char-star
            else if(k==2*i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;

    }

        //2ND-HALF
    for(int i=0;i<rows;i++){

        //spaces
        for(int j=0;j<i;j++){
            cout<<" ";
        }
            //starts
        for(int k=0;k<2*rows-2*i-1;k++){
            if(k==0){
                cout<<"*";
            }
            else if(k==2*rows-2*i-2){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
}
int main(){
    diamond(6);
}