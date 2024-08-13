#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
int binary_search(vector<int>&nums,int s,int target){
    int e=nums.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;

    }
    return -1;

}
// 1.METHOD-Sorting then 2 pointer approach
int findPairs1(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    set<pair<int,int>>ans;//handling dulpicate pairs
    int L=0;
    int R=1;
    while(R<nums.size()){
        
        int diff=nums[R]-nums[L];
        if(diff==k){
            ans.insert({nums[L],nums[R]});//will only insert unique pairs
            cout<<"pair:("<<nums[L]<<","<<nums[R]<<")";
            L++;
            R++;
        }
        else if(diff>k){
            L++;// to reduce the diff
        }else{
            R++;
        }
        if(R==L){
            R++;
        }
    }
    return ans.size();
        
}    

// 2.METHOD- sort and then binary search
int findPairs2(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    set<pair<int,int>>ans;//handling dulpicate pairs
    // we know that nums[i]-nums[j]=k
    // so nums[j]=k+nums[i] let k+nums[i]=element 
    // we search for this element in the remaning array if it exists->pair with k diff exists
    for(int R=0;R<nums.size();R++){
        
        if(binary_search(nums,R+1,k+nums[R]) !=-1){
            //meaning that element is found
            ans.insert({nums[R],k+nums[R]});
            
        }
       

    }
    return ans.size();
   

        
}


int main(){

    vector<int>nums{3,1,4,1,5};
    // cout<<endl<<"the no of unique pairs are:"<<findPairs1(nums,2);

    cout<<"the no of unique pair are:"<<findPairs2(nums,2);
}