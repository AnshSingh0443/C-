#include<iostream>
#include<vector>
using namespace std;
// we will try to put each elem at each index while cheching the condition perm[i]%i==0 or i%perm[i]==0
// eg if n=3 1-indexed array will be 123 so we will try to put 1,2 and 3 at every index
    void countArrangementHelper(vector<int>&v,int& ans,int n,int currNum){
        //base case->last elem has been placed 
        if(currNum==n+1){
            //printing
            for(int i=1;i<=n;i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
            ++ans;
            return;
        }

        for(int i=1;i<=n;i++){
            //condition->ith place is empty and can be a beautifull arrangement
            if(v[i]==0 && (currNum%i==0 || i%currNum==0)){
                v[i]=currNum;
                //R.R
                countArrangementHelper(v,ans,n,currNum+1);
                //backtrack
                v[i]=0;

            }
        }
    }
    int countArrangement(int n) {
        vector<int>v(n+1);// 1-indexed we will igonre 0
        int ans=0;
        countArrangementHelper(v,ans,n,1);
        //1->curr number->1 to n
        return ans;
        
    }
int main(){
    // Suppose you have n integers labeled 1 through n. 
    // A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n),
    // either of the following is true:
    //  1.perm[i] is divisible by i.
    //  2.i is divisible by perm[i].
    //  
    //Given an integer n, return the number of the beautiful arrangements that you can construct.

    

    // Example 1:

    // Input: n = 2
    // Output: 2
    // Explanation: 
    // The first beautiful arrangement is [1,2]:
    //     - perm[1] = 1 is divisible by i = 1
    //     - perm[2] = 2 is divisible by i = 2
    // The second beautiful arrangement is [2,1]:
    //     - perm[1] = 2 is divisible by i = 1
    //     - i = 2 is divisible by perm[2] = 1
    int n=3;
    countArrangement(n);
}