#include<iostream>
#include<vector>
using namespace std;
int solve(int dividend,int divisor){
    int s=0;
    int e=abs(dividend);
    int mid=s+(e-s)/2;
    int quotient=0;
    while(s<=e){
        if(abs(mid*divisor)==abs(dividend)){
            quotient=mid;
            return quotient;
        }
        else if(abs(mid*divisor)<abs(dividend)){
            quotient=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    //handling negative
    if(divisor>0&&dividend>0 || divisor<0&&dividend<0){
        return quotient;
    }
    else{
        return -quotient;
    }
    
}
int main(){
    // if 10/2 the answer or quotient should be in the range of 0-------mid--------10
    // applying bs
    // s=0,e=10,mid=s+e-s/2
    // as quotient*divisor+rem=divided
    // no need for rem so 
    // qoutient*divisor<=dividend
    // let say mid is the answer by checking if mid*divisor(2)==dividend(10)
    int dividend=20;
    int divisor=3;
    int ans=solve(dividend,divisor);
    cout<<"the qoutient is->"<<ans;
    cout<<endl;
    //factional part
    // int precision;
    // cout << "Enter the number of floating digits in precison "<<endl;
    // cin >> precision;

    // double step = 0.1;
    // double finalAns = ans;
    // for(int i=0; i<precision; i++) {

    //   for(double j=finalAns; j*divisor<=dividend; j = j + step) {
    //       finalAns = j;
    //   }
    //   step = step / 10;
    // }
    // cout << "Final ans is. "<< finalAns << endl;
    return 0;

}    
        