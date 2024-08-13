#include<iostream>
#include<vector>
using namespace std;
// 1METHOD.2-pointer approach
vector<int> findClosestElements1(vector<int>&arr, int k, int x) {
    vector<int>ans;
    int L=0;
    int R=arr.size()-1;
    while(R-L>=k){
        if(abs(x-arr[L])>abs(x-arr[R])){
            L++;
        }else{
            R--;
        }
    }
    for(int i=L;i<=R;i++){
        ans.push_back(arr[i]);
    }
    return ans;
}


// 2.METHOD
// first Find closest element->(binary search) to x and initilize a pointer R(right) to its index and L to R-1 
// then expand a window[L,R] of size =k using some conditions this will window will contain the k closest elements


int main(){
    vector<int>arr{1,2,3,4,5};
    // 1.method-two pointer
    vector<int>res=findClosestElements1(arr,4,3);//k=4 and x=3
    for(auto i:res){
        cout<<" "<<i;
    }

}