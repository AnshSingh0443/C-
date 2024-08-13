#include<iostream>
#include<math.h>
using namespace std;
//1.Euclid algorithm 
// gcd(a,b)=gcd(a-b,b) a > b
//       or=gcd(b-a,a) b > a
//       or=gcd(a%b,b) but modulous op is heavy so prefer above 

//Algo->do gcd(a,b)=gcd(a-b,a) till one of the param becomes ZERO
// then the other param is the answer(hcf/gcd)
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
int main(){
    //GCD->Greatest Common Divisior
    //HCF->Highest Common factor
    //-> a num is considered hcf/gcd of two nums a and be if it is the highest num(max) that fully divides a and b
    cout<<gcd(72,24);

}