#include<iostream>
#include<vector>
using namespace std;
int findPivot(vector<int>arr){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        //when array is fully sorted and not rotated
        if(s==e){
            return s;
        }
        if(mid+1<e && arr[mid]>arr[mid+1]){
            return mid;
        }
        if( mid-1>=s  && arr[mid]<arr[mid-1]){
            return mid-1;
        }
        if(arr[s]>arr[mid]){
            //pivot must be on the left side
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;

}
//binary search
int binarysearch(vector<int>arr,int s,int e,int target){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]>target){
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
        
}

int search(vector<int>& nums, int target) {
    int pivotIndex=findPivot(nums);
    int ans=0;
    if(target>=nums[0]&&target<=nums[pivotIndex]){
       ans= binarysearch(nums,0,pivotIndex,target);
    }else{
        ans=binarysearch(nums,pivotIndex+1,nums.size()-1,target);
    }
    return ans;

        
}
int main(){
    //given that array is rotated find  pivot  index
    //array-rotated+sortd array with no dulpicates
    vector<int>arr{9,10,2,4,6,8};
    int pivotindex=findPivot(arr);
    cout<<"pivot is at index "<<pivotindex <<" which is "<<arr[pivotindex];
    //now search for target in the array using pivot 
    cout<<endl<<"and the target is at index:"<<search(arr,6);
    
    

}