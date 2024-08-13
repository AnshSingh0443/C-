#include<iostream>
#include<vector>
using namespace std;
   //method 2
    int search(vector<int>& nums, int target) {
        int low =0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }

            //left is sorted 
            if(nums[low]<=nums[mid]){
                //if target is present in the left part
                if(nums[low]<=target && target<=nums[mid]){
                    //eliminate right part
                    high=mid-1;
                }else{
                    //eliminate the left  part
                    low=mid+1;
                }
            }
            //right is sorted
            else{
                //if target oiss present in the right  part
                if(nums[mid]<=target && target<=nums[high]){
                    //eliminate the left part
                    low=mid+1;
                }else{
                    //eliminate the right part
                    high=mid-1;
                }
            }
            
        }
        return ans;
           
    }
int main(){
    vector<int>nums ={4,5,6,7,0,1,2};
    int target = 0;
    cout<<search(nums,target);



}