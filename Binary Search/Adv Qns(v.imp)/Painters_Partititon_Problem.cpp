#include<iostream>
#include<vector>
using namespace std;

bool IsPossibleSoultion(vector<int>A,int k,int n,long long mid){
    int count=1;//keep count of painters
    int time_sum=0;
    for(int i=0;i<n;i++){
        if(A[i]>mid){
            return false;
        }
        if(time_sum+A[i]>mid){
            count++;
            time_sum=A[i];
            if(count>k){
                return false;
            }
        }else{
            time_sum+=A[i];
        }
    }
    return true;
}
long long minTime(vector<int>A, int n, int k){
    if(k>n){
        return -1;
    }

    long long s=0;
    long long total_time=0;
    for(int i=0;i<n;i++){
        total_time+=A[i];
    }
    long long ans=-1;
    long long e=total_time;
    while (s<=e){
        long long mid=s+(e-s)/2;
        if(IsPossibleSoultion(A,k,n,mid)){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    
    }
    return ans;
        
}
      

int main(){
    //PROBLEM STATEMENT
    //Dilpreet wants to paint his dog's home that has n boards with different lengths. 
    //The length of ith board is given by arr[i] where arr[] is an array of n integers. 
    //He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 
    //The problem is to find the minimum time to get this job done if all painters start together with the constraint 
    //that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.

    //EXAMPLE
    // Input:
    // n = 5
    // k = 3
    // arr[] = {5,10,30,20,15}
    // Output: 35
    // Explanation: The most optimal way will be:
    // Painter 1 allocation : {5,10}
    // Painter 2 allocation : {30}
    // Painter 3 allocation : {20,15}
    // Job will be done when all painters finish
    // i.e. at time = max(5+10, 30, 20+15) = 35



    vector<int>A{5,10,30,20,15};//lenght of ith board ,1unit of length  =1 unit of time
    int k=3;//painters
    int n=A.size();//no of boards
    cout<<minTime(A,n,k);


    
}