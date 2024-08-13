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
int main(){
    //array-rotated+sortd array with no dulpicates
    vector<int>arr{9,10,2,4,6,8};
    int ans=findPivot(arr);
    cout<<"pivot is at index "<<ans <<" which is "<<arr[ans];
    

}