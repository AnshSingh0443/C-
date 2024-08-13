#include<iostream>
#include<vector>
using namespace std;
    void helper(int i,vector<int>&currComb,vector<vector<int>>&ans,int n,int k){
        //base case
        if(currComb.size()==k){
            ans.push_back(currComb);
            return;
        }
        if(i>n){
            return;
        }

        //include
        currComb.push_back(i);
        helper(i+1,currComb,ans,n,k);
        currComb.pop_back();

        //exclude
        helper(i+1,currComb,ans,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>currComb;
        vector<vector<int>>ans;
        int i=1;
        helper(i,currComb,ans,n,k);
        return ans;

    
        
    }

// Time: O(k * C(n, k))
vector<vector<int>> combinations2(int n, int k) {
    vector<vector<int>> combs;
    vector<int> curCombs;
    helper2(1, curCombs, combs, n, k);
    return combs;
}

void helper2(int i, vector<int>& curComb, vector<vector<int>>& combs, int n, int k) {
    if (curComb.size() == k) {
        combs.push_back(vector<int>(curComb));
        return;
    }
    if (i > n) return;

    for (int j = i; j < n + 1; j++) {
        curComb.push_back(j);
        helper2(j + 1, curComb, combs, n, k);
        curComb.pop_back();
    }
}
int main(){

    int n=4;
    int k=2;
    vector<vector<int>>res=combine(n,k);

    for(auto a:res){
        for(auto b:a){
            cout<<b;
        }
        cout<<" ";
        
    }

}