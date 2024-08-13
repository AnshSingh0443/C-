#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
//<Noraml-Sieve-> prime no in the range 0 to n
vector<bool>Sieve(int n){
    int count=0;
    
    vector<bool>sieve(n+1,true);
    sieve[0]=sieve[1]=false;

    for(int i=2;i<=n;i++){
        if(sieve[i]){
            int j=i*2;//multiple of i starting table from 2
            while(j<=n){
                sieve[j]=false;//mark multiple as  false
                j=j+i;//continue the table till it is less than n
            }
        }
    }
    return sieve; 

}

//Optimising sieve of eratostheses
//1.Optimization in the inner loop 
//instead of starting j=i*2 , we use j=i*i because all the values becfore i*i(i,e i*(i-1)....i*2) would already have been marked 
// eg  10,15,20, would already have been marked by table of 2 and 3 so when i=5 instead of starting the table of 5 from 2 we do it from 25
// ie instead of i*2(5*2->10(already marked)), we do->i*i(5*5) that is start marking from 25 
// ie->first unmarked will be at i*i

//2.optimization in outer loop
//instead of going from 2 till n we should only loop till sqrt(n)->i=2 till i<=sqrt(n)
//beacuse after a when i>sqrt(n) the first marked value i*i will be greater than n itsellf so no point in ruuning the loop
//eg n =25 and sqrt(25)=5 after the value 6 lets say 6 i*i=6*6=36>25(n) so no point in ruuning the loop till n 
vector<bool>Optimised_Sieve(int n){
    int count=0;
    
    vector<bool>sieve(n+1,true);
    sieve[0]=sieve[1]=false;
    int sqrtN=sqrt(n);

    for(int i=2;i<=sqrtN;i++){//2.optimization->loop till i<=sqrt(n)
        if(sieve[i]){
            int j=i*i;//1.optimization->first umarked->i*i
            while(j<=n){
                sieve[j]=false;
                j=j+i;
            }
        }
    }
    return sieve; 

}
int main(){
    
    vector<bool>sieve=Sieve(25);
    vector<bool>optimised_Sieve=Optimised_Sieve(50);

    for(int  i=0;i<sieve.size();i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;

    for(int i=0;i<optimised_Sieve.size();i++){
        if(optimised_Sieve[i]){
            cout<<i<<" ";
        }
    }

}