#include<iostream>
#include<vector>
using namespace std;

// void reverse(vector<int>&a,int start,int end){
   
//     while(start<=end){
//         swap(a[start],a[end]);
//         start++;
//         end--;
//     }
// }

int main(){
    vector<int>nums{1,2,3,4,5,6,7};
    cout<<"enter the value of k:";
    int k;
    cin>>k;
    int size=nums.size();
    vector<int>ans(size);
    for(int i=0;i<size;i++){
        ans[(i+k)%size]=nums[i];//shift ith term by k in a cyclic way
    }

    //made change to given array
    nums=ans;


    // //reversing tech
    // reverse(nums,0,nums.size()-1);
    // reverse(nums,0,k-1);//reversing 1st k elements
    // reverse(nums,k,nums.size()-1);



   
    for(auto value:nums){
        cout<<value<<" ";
    }
}