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
int last_occurence(vector<int>v,int n){
    int ans=0;
    int s=0;
    int e=v.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(v[mid]==n){
            ans=mid;
            s=mid+1;//last occurence so check if it is present in the 2nd half of the array
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
    //total_occurence=last_occurence-first_occurence+1
    //array must be  sorted
    vector<int>v{1,2,3,3,3,4,5};
    int first=first_occurence(v,3);
    int second=last_occurence(v,3);
    int total_occurence=second-first+1;
    cout<<total_occurence;

}