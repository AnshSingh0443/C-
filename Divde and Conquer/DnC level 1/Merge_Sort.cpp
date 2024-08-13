#include<iostream>
using namespace std;
// T.C of merge sort->o(nlogn)

void Merge(int* arr,int s,int e){
    // here arr will be sorted in two parts 
    //1.Sorted from 0 to mid
    //2.Sorted from mid+1 to end
    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    //assume below code as->creating array of length len1 and len2
    int* left=new int[len1];
    int* right=new int[len2];

    //copy value in these array
    int k=s;
    for(int i=0;i<len1;i++){
        left[i]=arr[k];
        k++;
    }

    k=mid+1;
    for(int i=0;i<len2;i++){
        right[i]=arr[k];
        k++;
    }

    //merge logic->same as merging 2 sorted arrays
    //two pointers
    int leftIndex=0;
    int rightIndex=0;
    int MainArrIndex=s;

    //until one of array finishes
    while(leftIndex<len1 && rightIndex<len2){
        if(left[leftIndex]<right[rightIndex]){
            //place it in arr
            arr[MainArrIndex]=left[leftIndex];
            leftIndex++;
            MainArrIndex++;
        }else{
            arr[MainArrIndex]=right[rightIndex];
            rightIndex++;
            MainArrIndex++;
        }
    }

    //copy logic if elements are left in the array
    while(leftIndex<len1){
        arr[MainArrIndex]=left[leftIndex];
        MainArrIndex++;
        leftIndex++;
    }
    while(rightIndex<len2){
        arr[MainArrIndex]=right[rightIndex];
        MainArrIndex++;
        rightIndex++;
    }


}
void MergeSort(int* arr,int s,int e){
    //base case->single element or invalid array
    if(s>=e){
        return;
    }

    int mid=(s+e)/2;

    //left part
    MergeSort(arr,s,mid);

    //right part
    MergeSort(arr,mid+1,e);

    //here the whole array would  have been broken into  single elements(B.C)
    //now merge will be called when returning which will merge the array in sorted


    //merge sorted array
    Merge(arr,s,e);



}
int main(){
    int arr[]={2,15,45,19,4,7,31};
    int n=7;//size
    int e=n-1;
    int s=0;
    MergeSort(arr,s,e);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }



}