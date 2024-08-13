#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    int s=0;
    int e=nums.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        // Case1-single element in array
        if(s==e){
            return nums[s];
        }
        // Case2-mid is even
        if(mid%2==0){
            //we are on the left side
            if(nums[mid]==nums[mid+1]){
                //search right
                s=mid+2;//+2 beacuse mid+1 is already checked
            }
            // we are on right side
            else{
                //search left
                e=mid;//beacuse mid may be an answer
            }

        }
        // Case3-mid is odd
        else if(mid%2!=0){
            // we are on left side
            if(nums[mid]==nums[mid-1]){
                //search right
                s=mid+1;
            }else{
                e=mid;
            }
        }
        mid=s+(e-s)/2;
    }
    return -1;
        
}  
int main(){
    //pre-info
    //all elements occur even no of times expect one
    //all repeating occurence of elements appear in pairs eg,1,1,2,2,3,3(pairs)
    //pairs are not adjacent(eg 1,1,1,1 is not valid but 1,1,2,2,1,1 is valid)
    //there cant be more than 2 consecutive occurence of any element (eg 1,1,1 is not valid)
    

    // 1st apporach-XOR-o(n)
    //xor the whole array paies will be cancled and  odd one is the only one remaining 


    vector<int>nums{3,3,7,7,10,11,11};
 // ----------------0 1 2 3 4 5 6 7 8 9 10-----------------index
    //2nd apporach -index observations
    //LEFT Side- in a pair the 1st elemrnt is at even index and 2nd elem is at odd index
    //RIGHT side- in pair 1st elem-odd index and 2nd elem-even index
    // ans answer is always at even index (ans->3 index->4)
    cout<<singleNonDuplicate(nums);

}