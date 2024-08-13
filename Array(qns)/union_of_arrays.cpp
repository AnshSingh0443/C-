#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[]={1,2,3,3,4,5,-4,-2};
    int sizea=7;
    int brr[]={2,3,4,-2};
    int sizeb=4;
    
    vector<int>ans;
    for(int i=0;i<sizea;i++){
        int a=arr[i];
        for(int j=0;j<sizeb;j++){
            //handling duplicates
            if(a==brr[j]){
                //pushing dulpicated value
                ans.push_back(brr[j]);
                //marking in the other array that this value is already pushed
                a=INT_MIN;
            }
        
        }
        //only values that are not marked will be pushed into ans
        if(a!=INT_MIN){
            ans.push_back(a);
        }
       
    }    
    for(auto i:ans){
        cout<<i<<" ";
    }

       
    

}