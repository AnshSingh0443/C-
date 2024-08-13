#include<iostream>
using namespace std;
void numeric_hollow_half_pyramid(int n){
    for(int  i=0;i<n;i++){
        //print chars
        int start=2;
        for(int j=0;j<2*i+1;j++){
            if(j==0){
                cout<<j+1;
            }
            else if(i==n-1){
                if(j%2==0){
                    cout<<start;
                    start++;
                }else{
                    cout<<" ";
                }
            }
            else if(j==2*i){
                cout<<i+1;
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    numeric_hollow_half_pyramid(5);

}