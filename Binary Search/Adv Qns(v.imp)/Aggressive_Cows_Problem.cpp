#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool IsPossibleSolution(vector<int>&stalls ,int k, int mid){
    //this function checks if we can place k cows with at least mid distance between them
    int count=1;// keep track of k cows
    int cow=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-cow>=mid){
            count++;
            cow=stalls[i];//one more cow placed
            if(count==k){
                return true;
            }
        }

    }
    return false;    

}
int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(),stalls.end());
    // no of cows>no of stalls
    if(k>n){
        return -1;
    }
    int s=0;
    int e=stalls[stalls.size()-1]-stalls[0];//or  last elem as stalls is sorted
    int ans=-1;
    while(s<=e){
     // mid-represents the least dis at which cows  can be placed and then we maximize this mid
        int mid=s+(e-s)/2;
        if(IsPossibleSolution(stalls,k,mid)){
            ans=mid;
            s=mid+1;//maximize the min
        }else{
            e=mid-1;
        }
    }
    return ans;

}
int main(){
    //PROBLEM  STATEMENT
    //You are given an array consisting of n integers which denote the position of a stall.
    //You are also given an integer k which denotes the number of aggressive cows.
    //You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
    //The first line of input contains two space-separated integers n and k.
    //The second line contains n space-separated integers denoting the position of the stalls

    //EXAMPLE
    // Input:
    // n=5 
    // k=3
    // stalls = [1 2 4 8 9]
    // Output:
    // 3
    // Explanation:
    // The first cow can be placed at stalls[0], 
    // the second cow can be placed at stalls[2] and 
    // the third cow can be placed at stalls[3]. 
    // The minimum distance between cows, in this case, is 3, 
    // which also is the largest among all possible ways.
    vector<int>stalls{1 ,2, 4, 8, 9};//stalls[i] represent position of stall
    
    int n=stalls.size();//no of stalls
    int k=3;//no of cows
    cout<<solve(n,k,stalls);
}
