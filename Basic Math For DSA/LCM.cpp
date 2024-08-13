#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    //jab tak dono a aur b 0 se bade hai 
    //if any one becomes 0->break out of the loop
    while (a>0 && b>0){
        if(a>b){
            a=a-b;
        }
        else{
            //b>a
            b=b-a;
        }
    }
    return a==0?b:a;
    
}
int lcm(int a,int b){
    int ans=a*b/gcd(a,b);

    return ans;
}
int main(){
    //we know that->LCM(a,b)*HCF(a,b)=a*b
    // LCM(a,b)=a*b/HCF(a,b)
    cout<<lcm(72,24);
}