#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
    int maxWidthRamp(vector<int>& nums) {
        //brute force TLE
        // int max_width=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]<=nums[j]){
        //             int width=j-i;
        //             max_width=max(width,max_width);
        //         }
               
        //     }
        // }
        // return max_width;



        //SORTING
        // int n = nums.size();
        // vector<int> indices(n);

        // // Initialize the array with indices
        // for (int i = 0; i < n; i++) {
        //     indices[i] = i;
        // }

        // // Sort indices based on corresponding values in nums and ensure
        // // stability
        // sort(indices.begin(), indices.end(), [&](int i, int j) {
        //     return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
        // });

        // int minIndex = n;  // Minimum index encountered so far
        // int maxWidth = 0;

        // // Calculate maximum width ramp
        // for (int i = 0; i < n; i++) {
        //     maxWidth = max(maxWidth, indices[i] - minIndex);
        //     minIndex = min(minIndex, indices[i]);
        // }

        // return maxWidth;
    


        //two pointer / sliding window?
        int n = nums.size();
        vector<int> rightMax(n);

        // Fill rightMax array with the maximum values from the right
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int left = 0, right = 0;
        int maxWidth = 0;

        // Traverse the array using left and right pointers
        while (right < n) {
            // Move left pointer forward if current left exceeds rightMax
            while (left < right && nums[left] > rightMax[right]) {
                left++;
            }
            maxWidth = max(maxWidth, right - left);
            right++;
        }

        return maxWidth;
       
    }

int main(){

}