#include<iostream>
using namespace std;
    bool isPowerOfTwo(int n) {
        //edge case
        if(n==0 || n==INT_MAX || n==INT_MIN){
            return false;
        }
        int ans=(n&(n-1));
        if(ans==0){
            return true;
        }
        else
            return false;
        
    }
int main(){
    
}