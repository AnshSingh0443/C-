#include<iostream>
using namespace std;
void flipped_Solid_diamond(int n){
    
    for(int i=0;i<n;i++){
        //1ST-PART
        //stars
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        for(int k=0;k<i;k++){
            cout<<" ";
        }

        //2ND-PART
        //spaces
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        //stars
        for(int k=0;k<n-i;k++){
            cout<<"*";
        }
        cout<<endl;
      
    }

    for(int i=0;i<n;i++){
        //part-3
        //stars
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        //spaces
        for(int k=0;k<n-i;k++){
            cout<<" ";
        }
        
        //part4
        //spaces
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        //stars
        for(int k=0;k<i;k++){
            cout<<"*";
        }
        cout<<endl;
    }
    
    
    
    
    
}
int main(){
    flipped_Solid_diamond(5);

}