#include<iostream>
#include<vector>
using namespace std;

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

   
    for(auto value:nums){
        cout<<value<<" ";
    }
}
