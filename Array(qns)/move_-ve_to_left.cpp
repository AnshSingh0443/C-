#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr{1,2,-3,-4,-5,6};

    int start=0;
    int i=0;
    int end=arr.size()-1;

    while(start<end){
        if(arr[i]<0){
            swap(arr[i],arr[start]);
            start++;
            i++;
        }else{
            swap(arr[i],arr[end]);
            end--;
        }
    }
    for(auto value:arr){
        cout<<value<<" ";
    }
}