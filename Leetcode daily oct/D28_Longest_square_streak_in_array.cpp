#include<unordered_map>
#include<set>
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    //brute nlogn->using unordered_map
    int longestSquareStreak_1(vector<int>& nums) {
        //sorting
        sort(begin(nums),end(nums));
        //map to store no and its max streak
        unordered_map<int,int>mp;

        int result=-1;

        for(auto &num :nums){
            //steps if it sqroot(num) is present -> add  it to mp  with its maxstreak as 1+max streak of  sqroot(num)
            int root=(int)sqrt(num);

            //check if valid root or not  and it is present in the map
            if(root*root==num && mp.find(root)!=mp.end()){
                mp[num]=1+mp[root];
            }else{
                mp[num]=1;
            }
            result=max(result,mp[num]);
        }

        if(result>=2){
            return result;
        }
        return -1;

    }
    //Approach-2 (Using set)
    //T.C : O(n) ///Note : O(n) because while loop will run max 5 times. So if constraint is given, then saying O(n) time complexity is fine.
    //S.C : O(n)
    int longestSquareStreak_2(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));

        int maxStreak = 0;

        for(int &num : nums) {
            int streak = 0;
            long long curr = num;

            while(st.find(curr) != st.end()) {
                streak++;

                if(curr*curr > 1e5) {
                    break;
                }

                curr = curr*curr; //square
            }

            maxStreak = max(maxStreak, streak);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }

    //DP
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<int>dp(n,1);
        for(int i = 1;i < n; i++){
            int sr = sqrt(nums[i]);
            if(1LL*sr*sr == nums[i]){
                int ind = lower_bound(nums.begin(),nums.end(),sr) - nums.begin();
                if(ind < n && nums[ind] == sr) dp[i] = 1 + dp[ind];
                else    dp[i] = 1;
            }
            else    dp[i] = 1;
        }
        int maxi = *max_element(dp.begin(),dp.end());
        return maxi == 1 ? -1 : maxi;
    }
};


int main(){

}