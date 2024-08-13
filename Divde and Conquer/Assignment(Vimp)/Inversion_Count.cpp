#include<iostream>
#include<vector>
using namespace std;
//method 1->t.c->o(n^2)
int countInversion(vector<int>arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;


}

long merge(vector<int>&arr,vector<int>&temp,int start,int mid,int end){
    int i=start;
    int j=mid+1;
    int k=start;
    long count=0;
    while(i<=mid&&j<=end){
        if(arr[i]>arr[j]){
            temp[k++]=arr[j++];
            count+=mid-i+1;
        }else{
            temp[k++]=arr[i++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }

    while(start<=end){
        arr[start]=temp[start];
        ++start;
    }
    return count;
    
}
long mergeSort(vector<int>&arr,vector<int>&temp,int start,int end){
    if(start>=end){
        return 0;
    }
    int mid=start+(end-start)/2;
    long c=0;
    c=c+mergeSort(arr,temp,start,mid);//left array
    c=c+mergeSort(arr,temp,mid+1,end);//right array

    c=c+merge(arr,temp,start,mid,end);//mergeing the arrays

    return c;

}

//M2->Merge sort->while merging we commpare the values of left and right array and increment count accordingly
long countInversion2(vector<int>&arr){
    long count=0;
    vector<int>temp(arr.size(),0);//temp  array used while ddoing merge sort initilized with 0
    count=mergeSort(arr,temp,0,arr.size()-1);

    return count;

}
int main(){
    //Inversion count->no of swaps req to sort an array
    vector<int>arr{8,4,2,1};
    //swaps->(8,4),(8,2),(8,1),(4,2),(4,1),(2,1)->total 6

   cout<<countInversion2(arr);


}