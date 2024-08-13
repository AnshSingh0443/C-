#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<int>& arr,int target) {
    //Base case
    if(target==0){
        return 0;
    }
    if(target<0){
        return INT_MAX;
    }

    //solve one case
    //for each element in the array there will be a function call for every element in the array
    int mini=INT_MAX;
    for(int i=0;i<arr.size();i++){
        //functionn call
        int ans = solve(arr,target-arr[i]);// ans here is the no of elements req to reach target-arr[i]
        
        if(ans!=INT_MAX)//->means ans is valid value target sum is reached
        mini=min(mini,ans+1);// we add +1 in order to reach target since ans->ans here is the no of elements req to reach target-arr[i]
    }
    return mini;

}

int main() {
//PRoblem statement 
//->an array exists of length n that contains only unique elements
//->and a target is given and using the elements in the array we need to make up the target
//->we need to return the minimum no of elements that are required to reach target sum

vector<int>arr{1,2};
int target=5;// 5 can be made by 11111,1211,221
int ans=solve(arr,target);
cout<<"the answer is :"<<ans<<endl;


}