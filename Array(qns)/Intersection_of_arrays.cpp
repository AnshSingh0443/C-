#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[]={1,2,3,3,4,5,-4,-2};
    int sizea=8;
    int brr[]={2,3,3,4,-2};
    int sizeb=5;
    
    vector<int>ans;
    for(int i=0;i<sizea;i++){
        int a=arr[i];
        for(int j=0;j<sizeb;j++){
            if(a==brr[j]){
                //mark that element
                brr[j]=INT_MIN;
                ans.push_back(a);
            }
        }
       
    }    
    for(auto i:ans){
        cout<<i<<" ";
    }
}    