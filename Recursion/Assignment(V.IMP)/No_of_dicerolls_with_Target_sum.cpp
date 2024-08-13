#include<iostream>
#include<vector>
using namespace std;
int MOD=10000007;
//T.C->O(k^n)
int numRollsToTarget(int n,int k,int target){
    //note we will go from target to 0 and n to 0
    //base cases
    //if target becomes negative
    if(n<0 || target<0){
        return 0;
    }
    //if n and target both become 0->answer
    if(n==0 && target==0){
        return 1;
    }
    // target is not achieved using all n dices
    
    if(n==0 && target!=0){
        return 0;
    }
   // target is achieved without using all n dices-> not a valid answer
    if(n!=0 && target==0){
        return 0;
    }
    //k faces possible for each dice
    int ans=0;
    for(int i=1;i<=k;i++){
        ans=ans+numRollsToTarget(n-1,k,target-i);
    }

    return ans;

}
//2. Memoization
int numRollsToTarget_TOPDOWN(int n,int k,int target,vector<vector<int>>&dp){
    if(n<0 || target<0){
        return 0;
    }
    //if n and target both become 0->answer
    if(n==0 && target==0){
        return 1;
    }
    // target is not achieved using all n dices
    
    if(n==0 && target!=0){
        return 0;
    }
   // target is achieved without using all n dices-> not a valid answer
    if(n!=0 && target==0){
        return 0;
    }
    //step 2: check for ans in dp 
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
    //k faces possible for each dice
    int ans=0;
    for(int i=1;i<=k;i++){
        int recAns=0;
        if(target-i>=0){
            recAns=numRollsToTarget_TOPDOWN(n-1,k,target-i,dp);
        }
        //we are told to mod the answer
        ans=(ans%MOD + recAns%MOD)%MOD;
    }

   //step 3:update the dp
   dp[n][target]=ans;

   return dp[n][target];

}
//3.Tabulation
int numRollsToTarget_BOTTOMUP(int n,int k,int target){
    //step 1:create a dp array
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    //step 2 :observe base case
    dp[0][0]=1;//when both n and target is 0 -> 1(possible soln)
    //step 3 :reverse flow of top down 
    //index->o to n-1
    for(int index=1;index<=n;index++){
        //target(t) 0 to target
        for(int t=1;t<=target;t++){
            //k faces possible for each dice
            //replace rec call with dp and n with index also targrt with t
            int ans=0;
            for(int i=1;i<=k;i++){
                int recAns=0;
                if(t-i>=0){
                    recAns=dp[index-1][t-i];
                }
                //we are told to mod the answer
                ans=(ans%MOD + recAns%MOD)%MOD;
            }
            dp[index][t]=ans;

        }
    }
    return dp[n][target];
}

//4.th Space optimized
int solveUsingTabulationSO(int n, int k, int target) {

    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);

    prev[0] = 1;

    for(int index = 1; index <=n; index++) {
        for(int t=1; t<=target; t++) {

            long long int ans = 0;
            for(int i=1; i<=k; i++) {
                long long int recAns = 0;
                if(t - i >= 0 )
                    recAns = prev[t-i];//prev=dp[index-1]
                ans = (ans % MOD + recAns % MOD) % MOD;
            }
            curr[t] =  ans;//curr=dp[index]
        }
        //shift
        prev = curr;
    }

    return prev[target];

}
int main(){
    int n=3;//total no of dice must be thrown
    int k=6;//each dice has k faces->1,2,3,4.. to k
    int target=12;//after throwing 3 dices with 6 faces each->how many ways in which we can get sum-> target

    cout<<"total no of ways to reach target "<<target<<" using "<<n<<" dices with "<<k<<" faces each is "<<numRollsToTarget(n,k,target)<<endl;

    //soln using dp
    //step 1:create a dp array
    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

    cout<<"total no of ways to reach target "<<target<<" using "<<n<<" dices with "<<k<<" faces each is "<<numRollsToTarget_TOPDOWN(n,k,target,dp)<<endl;

}