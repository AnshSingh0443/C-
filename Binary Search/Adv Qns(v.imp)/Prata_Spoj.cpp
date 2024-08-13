#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool IsPossibleSolution(vector<int>RanksOfCooks,int P,int C,int mid){
    int currP=1;//intially cooked parta count
    for(int i=0;i<C;i++){
        int rank=RanksOfCooks[i];//rank of current cook
        int j=1;// to calculate 1R+2R+3R..and so on R->rank
        int timetaken=0;
        while(true){
            if(timetaken+j*rank<=mid){
                currP++;
                timetaken=timetaken+(j*rank);
                j++;
            }
            else{
                break;
            }

        }
        if(currP==P){
            return true;
        }
        
        
    }
    return false;
}
int MinTimeToCompleteOrder(vector<int>RanksOfCooks,int P,int C){
    sort(RanksOfCooks.begin(),RanksOfCooks.end());
    int start=0;
    int highestrank=RanksOfCooks[C-1];
    int end=highestrank*(P*(P+1)/2);//end should be the time taken to cook with highest rank when all parta are given to him
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(IsPossibleSolution(RanksOfCooks,P,C,mid)){
            //means if mid is the time taken for order to complete
            ans=mid;//store the ans
            // check for lower time
            end=mid+1;
            
        }
        //order could not be completed in mid time
        else{
            start=mid+1;
        }

    }
    return ans;

}
int main(){
    //PROBLEM STATEMENT
    //IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
    // The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. 
    // The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). 
    // A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on
    // (he can only cook a complete prata) 
    // (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes
    // also he can cook only 3 pratas as he does not have enough time for the 4th prata). 
    // The webmaster wants to know the minimum time to get the order done. Please write a program to help him out

    vector<int>RanksOfCooks{1 ,2, 3, 4};//ith->cook with rank->RanksOfCooks[i]
    int P=10;// no of parta
    int C=RanksOfCooks.size();//no of cooks
    int res=MinTimeToCompleteOrder(RanksOfCooks,P,C);
    cout<<"min time to complete order is-> "<<res;


}