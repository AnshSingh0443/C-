#include<iostream>
using namespace std;
int main(){
    //n can go only till 9
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num_start_index=8-i;
        int num=i+1;
        int num_count=num;
        for(int j=0;j<17;j++){
            if(j==num_start_index&&num_count>0){
                cout<<num;
                num_start_index=num_start_index+2;
                num_count--;
            }else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    
}