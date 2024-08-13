#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
//sieve of eratotheses
vector<bool>Sieve(int n){
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
//Segemented sieve->
// 1.Generate all primes responsible to mark seg sieve using Sqrt(R)->using normal sieve of eratotheses 
// 2.staarting marking from->  j=max(first multiple,prime*prime) ie firstm multiple=(L/prime)*prime
vector<bool>segmented_sieve(int L,int R){
    vector<bool>sieve=Sieve(sqrt(R));
    vector<int>BasePrime;
    for(int i=0;i<sieve.size();i++){
        if(sieve[i]){
            BasePrime.push_back(i);
        }
    }
    vector<bool>Segsieve(R-L+1,true);
    if(L==0||L==1){
        Segsieve[L]=false;
    }
    for(auto prime:BasePrime){
        int first_mul=(L/prime)*prime;
        if(first_mul<L){
            first_mul=first_mul+prime;
        }
        int j=max(first_mul,prime*prime);
        while(j<=R){
            Segsieve[j-L]=false;
            j=j+prime;
        }
    }
    return Segsieve;
}
int main(){
    //Prime Numbers in the range of (L,R)
    int L=110;
    int R=130;
    vector<bool>Seg_sieve=segmented_sieve(L,R);

    for(int i=0;i<Seg_sieve.size();i++){
        if(Seg_sieve[i]){
            cout<<" "<<i+L;
        }
    }
}