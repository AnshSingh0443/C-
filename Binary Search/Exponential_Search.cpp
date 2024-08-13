#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binary_search(vector<int>&nums,int s,int e,int target){
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
int exponential_search(vector<int>&nums,int target){
    int n=nums.size();
    
    if(nums[0]==target){
        return 0;
    }
    int i=1;
    while(i<nums.size() && nums[i]<=target){
        i=i*2;//increase exponential 1,2,4,8,16,32...and so on 
    }
    //here i will be at the last index of the subarray where nums[i]>target
    // and the starting index will be the prev i which is i/2
    int search=binary_search(nums,i/2,min(i,n-1),target);//nim(i,n-1) because in case i gets out of bounds we can take last index(n-1)as i
    return search;
}

int main(){
    //use case-when array is sorted but size is very large(infinity)
    //instead of searching the whole array we apply binary search in a subarray that contains that element
    // to find that subarray:exponentially increase the index until nums[i] is <= target-->gives start and end  index of subarray
    vector<int>nums{3,4,5,6,11,13,14,15,56,70};
    int target=13;
    
    int ans=exponential_search(nums,target);
    cout<<ans;


    //we use exponential search in case of array with infinite size 
    // algo:-
    if(nums[0]==target){
        return 0;
    }
    int i=0;
    int j=1;
    while(nums[j]<target){
        i=j;//i follows j
        j=j*2;//j increses exponential 
        // here i is always j/2;
    }
    int start=i; 
    int end=j;
    //and now we apply binary search

    
}