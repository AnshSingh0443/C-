#include<iostream>
#include<vector>
using namespace std;
int isPossibleSoultion(vector<int>A,int N,int M,int sol){
    int pagesum=0;
    int c=1;//count to keep track of students
    for(int i=0;i<N;i++){
        //if page exceed the possible sol then it can not be allocated
        if(A[i]>sol){
            return false;
        }
        if(pagesum+A[i]>sol){
            // excceds sol so allocate to next student
            c++;
            //allocation for next student starts
            pagesum=A[i];
            //allocation excceds no of students->sol is false
            if(c>M){
                return false;
            }     
        }
        else{
            pagesum+=A[i];
        }
    }
    return true;

}
int findPages(vector<int>A, int N, int M){
    // Case1-books can not be allocated as there are more no of student than book 
    // and it is must for each student to have atleast one book
    if(M>N){
        return -1;
    }
    int s=0;
    int totalpages=0;
    for(int i=0;i<A.size();i++){
        totalpages=totalpages+A[i];
    }
    int e=totalpages;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        //if mid(pages allocated at most) is a solution(N books can be assigned to M students with atmost mid pages)
        if(isPossibleSoultion(A,N,M,mid)){
            //it can be the answer
            ans=mid;
            //search for lower than this for minimum
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;

}
    
int main(){
    //PROBLEM STATEMENT:->
    // You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, 
    // with each student getting at least one book. Out of all the permutations, 
    // the goal is to find the permutation where the student with the most pages allocated to him gets the minimum number of pages, 
    // out of all possible permutations.

    // Note: Return -1 if a valid assignment is not possible, 
    // and allotment should be in contiguous order.


    //EXAMPLE
    // Input:
    // N = 4
    // A[] = {12,34,67,90}
    // M = 2
    // Output:113
    // Explanation:Allocation can be done in 
    // following ways:
    // {12} and {34, 67, 90} Maximum Pages = 191
    // {12, 34} and {67, 90} Maximum Pages = 157
    // {12, 34, 67} and {90} Maximum Pages =113.
    // Therefore, the minimum of these cases is 113,
    // which is selected as the output.
    vector<int>A{12,34,67,90};
    int N=4;//books 0 to 3
    int M=2;//students
    cout<<findPages(A,N,M);

    
   
}