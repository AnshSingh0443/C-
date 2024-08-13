#include<iostream>
#include<vector>
using namespace std;
int findPeakElement(vector<int>& nums) {
    int s=0;
    int e=nums.size()-1;
    int mid=s+(e-s)/2;
    int peak=-1;
            
    if(nums.size()==1){
        return 0;
    } 
    while(s<e){
        if(nums[mid]<nums[mid+1] && mid+1<=e){
            s=mid+1;
        }else{
            e=mid;
        }
        mid=s+(e-s)/2;   
    }
    return s;
                
}
int peakIndexInMountainArray(vector<int>& a){
    int s=0;
    int e=a.size()-1;
    int mid=s+(e-s)/2;
    int peak=-1;
    
    while(s<=e){
       //means that the mid can be peak or  can be in lineA
        if(a[mid]>a[mid+1]){
           
           e=mid-1;

        }
        //means arr[mid]<arr[mid+1] so mid can not be peak and peak can be in lineB
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return mid;

}

int main(){
    //array can be represented as 
    // 1.lineA-in which a[i]<ar[i+1](incresing)
    // 2.peak of mountain-arr[i-1]<arr[i](peak)>arrr[i+1]
    // 3.lineB-in which a[i]>ar[i+1](decreasing)
    vector<int>a{0,10,1,0};
    cout<<"the peak is at index "<<peakIndexInMountainArray(a);
}
