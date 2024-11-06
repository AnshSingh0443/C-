#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int no_of_set_bits(int n){
        int count = 0;
        
        while(n!=0){
            if((n&1) == 1){
                count++;
            }
            n = n>>1;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        //checking binary rep of 2 nos at the same tym if it is vlaid then we can swap them
        vector<int>dupNums(nums.begin(),nums.end());
        //using bubble sort
        //but swap omnly when If both elements have the same number of set bits, you are allowed to swap them
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(dupNums[j] > dupNums[j+1]){
                    //swap is needed
                    //check set bits
                    int count1=no_of_set_bits(dupNums[j]);
                    int count2=no_of_set_bits(dupNums[j+1]);

                    if(count1==count2){
                        swap(dupNums[j],dupNums[j+1]);
                    }else{
                        return false;
                    }
                }
            }
        }

        return true;
    }
};


int main(){

}