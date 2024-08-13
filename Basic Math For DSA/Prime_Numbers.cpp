#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
//NAIVE APPROCAH-o(n^2)
//fxn to find if a num is prime or not
bool isPrime1(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int countPrimes1(int n) {
    int count=0;
    for(int i=2;i<n;i++){//outer loop
        if(isPrime1(i)){//inner loop->isprime fxn
            count++;
        }
    }
    return count;
        
}

//BETTER APPROACH-o(n*sqrt(n))
//better fxn to find if prime or not
bool isPrime2(int n){
    if(n<=1){
        return false;
    }
    // let n be non-prime
    // so n=a*b where a and b are factors of n
    // IF-> a > sqrt(n) and b > sqrt(n) THEN a * b > n which is not possible thus [a > sqrt(n) and b > sqrt(n)] this statement is wrong
    // so At least one of the factors(a or b) must be smaller than sqrt(n)
    // IF we can find any factor less thab sqrt(n)->PRIME
    int sqrtn=sqrt(n);
    for(int i=2;i<=sqrtn;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}


//3.Sieve of Eratosthenes->o(n*(log log n))
//a. make an array of nums from 2--to---n-1 and mark them all prime
//b. start from 2 till the end and mark all the no that comes in the table of 2 as non prime
//c. repeat step b till n-1 only for prime no
//d. rest element marked as prime will be  counted

int countPrimes2(int n) {
    int count=0;
    if(n==0) return 0;
    vector<bool>prime(n,true);//array is created o to n-1 all marked true(prime)
    prime[0]=prime[1]=false;// 0 and 1 are not prime,2-> smallest prie no

    for(int i=2;i<n;i++){
        if(prime[i]){
            count++;//keep count of prime no
            // i is a prime no->mark all multiples of i as non prime

            int j=i*2;//multiple of i starting table from 2
            while(j<n){
                prime[j]=false;//mark multiple as  false
                j=j+i;//continue the table till it is less than n
            }
        }
    }
    return count; 
            
}

//4.Segmented sieve->variation of Sieve of Eratosthenes
//low and high are given and we find prime no between the range(low,high)




int main(){
    //problem statement
    // Given an integer n, return the number of prime numbers that are strictly less than n.


    // Example 1:
    // Input: n = 10
    // Output: 4
    // Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

    int n=10;
    //1.Naive approach
    cout<<"there are "<<countPrimes1(n)<<" prime nums less than 10"<<endl;

    //2.Sieve of eratosthenes
    cout<<"there are "<<countPrimes2(n)<<" prime nums less than 10"<<endl;

}