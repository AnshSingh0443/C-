#include<iostream>
#include<vector>
using namespace std;
void QuickSort(vector<int>&arr,int start,int end){
    if(start>=end){
        return;
    }
    //pivot will be end
    int pivot=end;
    //two pointer which we will swap based on condition to create partition
    int i=start-1;
    int j=start;

    //Partition logic
    while(j<pivot){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    i++;//->right postion of pivot elemeent
    swap(arr[i],arr[pivot]);
    //partition created where elem before pivot elem are less than pivot elem and elem after pivot elem are greater than it

    //recursive call for the rest of the array
    QuickSort(arr,start,i-1);
    QuickSort(arr,i+1,end);
    
}

int main(){
    vector<int>arr={7,2,1,8,6,3,5,4};
    QuickSort(arr,0,arr.size()-1);

    for(auto i:arr){
        cout<<" "<<i;
    }



}
