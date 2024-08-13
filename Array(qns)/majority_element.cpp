#include<iostream>
#include<vector>
using namespace std;
//brute force
int majority(vector<int>arr){

    for(int i=0;i<arr.size();i++){
        
        int count=0;
        int maxcount=0;
        for(int j=i+1;j<arr.size();j++){
            int elem=arr[i];
            if(arr[j]==elem){
                count++;
            }
            if(count>maxcount){
                maxcount=count;
            }
            if(maxcount>=arr.size()/2){
                return arr[j]; 
            }
        }
    }
    return 0;

}
int main(){
    vector<int>arr{3,3,4,4};
    int count=0;
    int elem=0;
    int maxcount=0;


    // int result=majority(arr);
    // cout<<result;
   
   

    //using moores logic
    for(int i=0;i<arr.size();i++){
        //using moores algo will Only work if there exists a majority element in the array(occurenece>[n/2])
        if(count==0){
            elem=arr[i];
        }
        if(arr[i]==elem){
            count++;
        }else{
            count--;
        }
    }
    cout<<"the majority element is :"<<elem;
}