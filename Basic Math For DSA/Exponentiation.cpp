#include<iostream>
using namespace std;

int SlowExponentiation(int a,int b){
    //a^b=a*a*a*a...(b times)
    int ans=1;
    for(int i=1;i<=b;i++){
        ans=ans*a;
    }
    return ans;
}//T.C->o(b)

int FastExponentiation(int a,int b){
    int ans=1;
    while(b>0){
        if(b & 1){
            //odd
            ans=ans*a;
        }
        a=a*a;
        b=b/2;// or we can do b<<=1(right shift by 1)
    }
    return ans;

}//T.C->o(logb)
int main(){
    cout<<SlowExponentiation(5,4)<<endl;

}