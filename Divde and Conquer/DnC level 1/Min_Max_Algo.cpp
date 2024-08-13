#include<iostream>
#include<vector>
using namespace std;
void MinMax(vector<int>&arr,int low,int high,int& min,int& max){
    //base case 1->single element
    if(low>=high){
        min=arr[low];
        max=arr[low];
        return;
    }
    //base case 2->2 element in array
    if(low-high==1){
        if(arr[low]<arr[high]){
            min=arr[low];
            max=arr[high];
        }else{
            min=arr[high];
            max=arr[low];
        }
        return;
    }
    else{
        int mid=low+(high-low)/2;
        //mini and maxi will store minimum and maxximum for right array calls
        int mini=INT_MAX;
        int maxi=INT_MIN;
        //left calls
        MinMax(arr,low,mid,min,max);
        //right calls
        MinMax(arr,mid+1,high,mini,maxi);

        if(maxi>max){
            max=maxi;
        }
        if(mini<min){
            min=mini;
        }
        return;
    }

}
int main(){
    vector<int>arr={7,10,13,71,32,83,2};
    int min=INT_MAX;
    int max=INT_MIN;
    MinMax(arr,0,arr.size()-1,min,max);
    cout<<"Minimum in the array:"<<min<<endl;
    cout<<"Maximum in the array:"<<max;


}