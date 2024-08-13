#include<iostream>
#include<vector>
using namespace std;
int main(){
    //using elements itself to traverse all array
    // unvisted index is the  nums  that is missing
    vector<int>arr{1,3,5,3,4};

    //1ST METHOD
    // int ans=-1;
    // for(int i=0;i<arr.size();i++){
    //     int index=abs(arr[i]);
    //     if(arr[index-1]>0){
    //         arr[index-1]*=-1;
    //     }
    // }
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    //     if(arr[i]>0){
    //         ans=i+1;
    //     }
    // }
    // cout<<"the missing num is"<<ans;


    //2ND METHOD-swapping and sorting
    int i=0;
    while(i<arr.size()){
        int index=arr[i]-1;
        if(arr[i]!=arr[index]){
            swap(arr[i],arr[index]);
        }
        else{
            i++;
        }
    }

    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=i+1){
            cout<<i+1;
        }
    }

   
}