#include<iostream>
#include<vector>
using namespace std;

//but we modify the array
//visting method
int duplicate(vector<int>arr){
    int ans=-1;
    for(int i=0;i<arr.size();i++){
        int index=abs(arr[i]);
        if(arr[index]<0){
            ans=index;
            return ans;
        }
        arr[index]=-arr[index];
    }
    return ans;

}
int main(){
    //asumming that only elements that exists in ther array  are from 0 to n-1;
    //we can use the elements itself to traverse ALL indices of the array and mark them visted(-ve)
    //if we encounter a index which is already visted then it is the duplicate element

    vector<int>arr{1,2,3,4,4};//n=5 so only elements that can exist  are from 0 to n-1=4 so 0,1,2,3,4
    
    // cout<<duplicate(arr);


    //swapping method
    while(arr[0]!=arr[arr[0]]){
        swap(arr[0],arr[arr[0]]);
    }
    cout<<"duplicate num is:"<<arr[0];
}