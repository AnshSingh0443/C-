#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        //k <2^maxbit if maxbit=2 
        //k= <2^2->4
        //k=0,1,2,3
        vector<int>result;

        //step 1: find the overall xor
        int XOR=0;
        for(int i=0;i<n;i++){
            XOR ^=nums[i];
        }

        //To find flip, first find the mask having all bits set to 1
        //why flip instead of going thru all values of k we make a mask and xor it with overall xor to get max
        int mask=(1<<maximumBit)-1;//mask of len maxbit set to 1
        for(int i=0;i<n;i++){
            int k= XOR ^ mask;
            result.push_back(k);

            //remove last elem
            XOR = (XOR ^ nums[n-1-i]);
        }

        return result;
    }
};

int main(){

}