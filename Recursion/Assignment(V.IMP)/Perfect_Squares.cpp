#include<iostream>
#include<cmath>
#include<vector>
using  namespace std;
int numSquare(int n){
    //base case
    if(n==0){
        return 0;
    }
    if(n<0){
        return 0;
    }

    //solve one case
    int ans=INT_MAX;
    int i=1;
    int end=sqrt(n);

    while(i<=end){
        int perfectSquare=i*i;
        int NoOfPerfectSquares=1+numSquare(n-perfectSquare);
        if(NoOfPerfectSquares<ans){
            ans=NoOfPerfectSquares;
        }
        i++;

    }
    return ans;
    
}
int main(){
    // Given an integer n, return the least number of perfect square numbers that sum to n.

    // A perfect square is an integer that is the square of an integer; 
    // it is the product of some integer with itself. 
    // For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

    

    // Example 1:

    // Input: n = 12
    // Output: 3
    // Explanation: 12 = 4 + 4 + 4.
    int n=12;
    cout<<"no of perfect square numbers req to make "<<n<<" is "<<numSquare(n);

}