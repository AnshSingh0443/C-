#include<iostream>
using namespace std;
bool isSorted(int arr[],int size,int i){
    //base case->if the current element is smaller that the prev or we reach the end
    if(i==size-1){
        return true;
    }

    //solve ek case baki recursion
    //i->current index
    if(arr[i+1]<arr[i]){
        return false;
    }
    
    //R.R
    bool ans= isSorted(arr,size,i+1);
    return ans;
}
int main(){
    int arr[]={2,6,7,9,12,11};
    int size=6;
    cout<<isSorted(arr,size,0);


}