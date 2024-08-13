#include<iostream>
using namespace std;
int main(){
    int n;
    int ans=0;
    cin>>n;
    bool isNeagtive=false;
    if(n<=INT_MIN){
        return 0;
    }
    if(n<0){
        isNeagtive=true;
        n=-n;//convert to positive
    }
    while(n>0){
        if(ans >INT_MAX/10){
            return 0;
        }
        int digit=n%10;
        ans=ans*10+digit;
        n=n/10;
    }
    if(isNeagtive){
        cout<<-ans;
    }else{
        cout<<ans;
    }

    //BEST WAY
    // int result = 0;

    // while (x != 0)
    // {
    //     int tail = x % 10;
    //     int newResult = result * 10 + tail;
    //     if ((newResult - tail) / 10 != result) if overflow exixts the new result will not to equal to the prev result
    //     { return 0; }
    //     result = newResult;
    //     x = x / 10;
    // }

    // return result;

}