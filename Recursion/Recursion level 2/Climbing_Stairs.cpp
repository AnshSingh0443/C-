#include<iostream>
using namespace std;
int stair(int n){
    //Base case->agar 1st step pe jana hai-> only 1 step is req
    if(n==0||n==1){
        return 1;
    }
    //R.R->nth stair pe jana k liye two ways->ya toh n-1 se jump ->one step or n-2 se jump->  step
    return stair(n-1)+stair(n-2);
}
int main(){
    int n=3;
    cout<<stair(4);//total num of ways by which we can reach 4th stair

}