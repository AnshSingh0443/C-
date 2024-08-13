#include<iostream>
#include<vector>
using namespace std;
int first_occurence(vector<int>v,int n){
    int ans=-1;
    int s=0;
    int e=v.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(v[mid]==n){
            ans=mid;
            e=mid-1;//first ocuurence so check if it is present is the 1st half of the array
        }
        else if(v[mid]>n){
            e=mid-1;
        }
        else if(v[mid]<n){
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    //one way is to search linearly
    //2nd way is to use binary search 
    //array must be  sorted
    vector<int>v{1,2,3,3,3,4,5};
    cout<<first_occurence(v,3);

}