#include<iostream>
#include<vector>
using namespace std;
int binary_search(vector<int>v,int target){
    int s=0;
    int e=v.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e){
    //    mid in sorted is at ith index s0 in nearly sorted it can be at ith,i-1,i+1
        if(v[mid]==target){
            return mid; 
        }
        //mid should not go out of bounds and stop unnecessary checking
        else if(v[mid+1]==target && mid+1<=e){
            return mid+1;
        }
        //mid should not go out of bounds and stop unnecessary checking
        else if(v[mid-1]==target && mid-1>=e){
            return mid-1;
        }
        else if(v[mid]<target){
            s=mid+2;//+2 because mid+1 is already checked
        }
        else{
            e=mid-2;//-2 because mid-1 is already checked
        }
        mid=s+(e-s)/2;
    }

    return -1;
}
// soretd array-3,10,20,40,50,70,80>
// Nearly sorted-10,3,40,20,50,80,70 so elemnt at ith index in sorted array will be at ith,i+1,i-1 index in the nearly sorted array
int main(){
    vector<int>arr1{10,3,40,20,50,80,70};
    cout<<"target is at index "<<binary_search(arr1,10);

}