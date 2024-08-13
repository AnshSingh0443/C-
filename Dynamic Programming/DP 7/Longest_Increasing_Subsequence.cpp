#include<iostream>
#include<vector>
using namespace std;
//1.recursion
//T.c->o(2^n)
int getLengthOfLIS_REC(vector<int>&nums,int curr,int prev,vector<vector<int>> &ans,vector<int>&v){
    //base case index reaches the end
    if(curr>=nums.size()){
        ans.push_back(v);
        return 0;
    }

    //include
    int include=0;
    //we can inlcude only when the prev elem included(tracked using prev) is less than the curr elem (
    // or when we have to include the first elem
    if(prev==-1|| nums[prev]<nums[curr]){
        v.push_back(nums[curr]);
        //since we just included a elem prev will become the curr for the next tinne we include another element
        include=1+getLengthOfLIS_REC(nums,curr+1,curr,ans,v);

        v.pop_back();
       
    }
    

    //exclude
    //no change in prev since we did not include the elem
    int exclude=0+getLengthOfLIS_REC(nums,curr+1,prev,ans,v);

    //return the max length of LIS 
    return max(include,exclude);
}
//2.th Memoization
int getLengthOfLIS_TOPDOWN(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
    //note we since prev is initially -1 it is not a valid index so to make it a valdi index we do prev+1
    //replace prev+1 with prev when cheking and updating dp
    //base case index reaches the end
    if(curr>=nums.size()){
        return 0;
    }

    //check if answer is present in the dp aray
    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }


    //include
    int include=0;
    //we can inlcude only when the prev elem included(tracked using prev) is less than the curr elem (
    // or when we have to include the first elem
    if(prev==-1|| nums[prev]<nums[curr]){
        
        //since we just included a elem prev will become the curr for the next tinne we include another element
        include=1+getLengthOfLIS_TOPDOWN(nums,curr+1,curr,dp);

       
       
    }
    

    //exclude
    //no change in prev since we did not include the elem
    int exclude=0+getLengthOfLIS_TOPDOWN(nums,curr+1,prev,dp);

    //return the max length of LIS 
    dp[curr][prev+1]=max(include,exclude);

    return dp[curr][prev+1];

}

//3rd.Tabulation
int getLengthOfLIS_BOTTOMUP(vector<int>&nums){
    int n=nums.size();
    //step  1 : create a dp arrray
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    //step 2 : handlle base cases
    //when curr is at last index->0 already handled during initialization of dp


    //step 3: revrese flow of topdown
    //curr was going from 0 to n-1 in top down
    for(int curr=n-1;curr>=0;curr--){
        //prev was going from -1(curr-1) to n-1 
        for(int prev=curr-1;prev>=-1;prev--){
            //change rec calls to dp and use loop variables accordingly
            int include=0;
            if(prev==-1|| nums[prev]<nums[curr]){
                include=1+dp[curr+1][curr+1];
            }
            int exclude=0+dp[curr+1][prev+1];
            dp[curr][prev+1]=max(include,exclude);

        }
    }
    return dp[0][0];

}
//4th.Space optimized solution
//from above we can see that the curr row is depending upon curr+1 row
//so dp[curr]=currrow and dp[curr+1]=nextrow
int getLengthOfLIS_SO(vector<int>&nums){
    int n=nums.size();
    vector<int>CurrRow(n+1,0);
    vector<int>NextRow(n+1,0);

    for(int curr=n-1;curr>=0;curr--){

        for(int prev=curr-1;prev>=-1;prev--){
            //change dp[curr][] to currRow[] and dp[curr+1] to nextrow[]
            int include=0;
            if(prev==-1|| nums[prev]<nums[curr]){
                include=1+NextRow[curr+1];
            }
            int exclude=0+NextRow[prev+1];
            CurrRow[prev+1]=max(include,exclude);
        }
        //shift since we  are moving toward 0 pr UP
        NextRow=CurrRow;
    }
    return NextRow[0];

}

//5.th Optimmal soln->we will not generate all inreasing subsequences rather 
// we will create the LIS in which binary seach will be used
int OptimalSoln(vector<int>&nums){
    vector<int>ans;
    if(nums.size()==0){
        return 0;
    }
    //1st element will always be included
    ans.push_back(nums[0]);

    for(int i=1;i<nums.size();i++){
        //include the element only if it is greater that the prevously included elem
        if(nums[i]>ans.back()){
            //include
            ans.push_back(nums[i]);
        }else{
            //if it is not we will overwrite the ans array
            // to overwrite we need the index of just bada elem than nums[i] in the ans array
            //which will be done using binary search
            int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            //now we have the index of just bigger elem than nums[i] present in the ans array
            //overwrite
            ans[index]=nums[i];
        }
    }
    //LIS is stored in ans vector
    return ans.size();
    
}

int LIS(vector<int>&nums){
    int n=nums.size();
    int curr=0;
    int prev=-1;//keeping track of current and prev element
    vector<vector<int>>ans;// contains all the increasing subsequences
    vector<int>v;
    //step 1:create a dp array
    vector<vector<int>>dp(n,vector<int>(n+1,-1));

    int ans1=OptimalSoln(nums);

    //printing all increasing subsequence
    // cout<<"Printing all Incresing subsequences:-> "<<endl;
    // for(auto a:ans){
    //     for(auto b:a){
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    return ans1;

}

int main(){
    //LIS->longest increasing subsequene->longest subseequence in which elems are in increasing order\
    // eaxmple
    // Input: nums = [0,1,0,3,2,3]
    // Output: 4->[0,1,2,3]
    vector<int>nums{0,1,0,3,2,3};

    

    int ans=LIS(nums);
    cout<<"max length among all the increasing subsequences:->"<<ans<<endl;

 
    
}