#include<iostream>
#include<vector>
using namespace std;
void printSubarray(vector<int>& nums,int start,int end){
    //base case
    if(end>=nums.size()){
        return;
    }


    //solve one case
    for(int i=start;i<=end;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    //R.R
    printSubarray(nums,start,end+1);

}
int main(){
    vector<int>nums={1,2,3,4};
    for(int i=0;i<nums.size();i++){
        printSubarray(nums,i,i);
    }

}