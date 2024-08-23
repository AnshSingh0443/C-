#include<iostream>
#include<stack>
#include<vector>

//https://leetcode.com/problems/daily-temperatures/description/

using namespace std;
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // int n=temperatures.size();
        // //BRUTEFORCE->TLE
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(temperatures[j]>temperatures[i]){
        //             int days=j-i;
        //             ans.push_back(days);
        //             break;
        //         }else if(j==n-1){
        //             ans.push_back(0);
        //         }
        //     }
        // }
        // //last wala hamesha 0
        // ans.push_back(0);

        // return ans;

        
        //NEXT GREATER ELEMENT
        int n=temperatures.size();
        stack<int>st;//store indexes
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                //pop chote elements 
                st.pop();
            }
            if(st.empty()){
                //matlab koi bhi elem ni mila jo just bada ho
                res[i]=0;
            }else{
                //elem mil gaya -> jo just bada hai cal ans
                int ans=st.top()-i;
                res[i]=ans;
            }
            st.push(i);

        }
        return res;
        
    }

int main(){

}