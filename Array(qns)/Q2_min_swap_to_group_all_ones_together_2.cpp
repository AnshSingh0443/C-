#include<iostream>
#include<vector>

//https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/?envType=daily-question&envId=2024-08-02
using namespace std;
    int minSwaps(vector<int>& nums) {
        //Sliding Window
        //swaps=totalones-maxones in a window of total ones
        //1.count total no of one

        int totalones=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                totalones++;
            }
        }
        //handling circular case
        int n=nums.size();
        vector<int>temp(2*n);
        for(int i=0;i<temp.size();i++){
            temp[i]=nums[i%n];//{0,1,1,0}--->{0,1,1,0,0,1,1,0}
        }

        int i=0;
        int j=0;
        int currones=0;
        int maxones=0;
        while(j<2*n){
            if(temp[j]==1){
                currones++;
            }
            //chech window sizee
            if(j-i+1 > totalones){
                if(temp[i]==1){
                    currones--;
                }
                i++;
            }
            maxones=max(maxones,currones);
            j++;

        }

        int swaps=totalones-maxones;
        return swaps;
    }

int main(){
    
}