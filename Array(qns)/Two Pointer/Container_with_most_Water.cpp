#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>& height) {
    int left=0;
    int right=height.size()-1;
    int maxarea=0;
    while(left<right){
        int currheight=height[left];
        if(height[left]<height[right]){
            currheight=height[left];
        }
        else{
            currheight=height[right];
        }
        int currwidth=right-left;
        int currarea=currheight*currwidth;
        if(height[left]>height[right]){
            right--;
        }else{
            left++;
        }
        maxarea=max(currarea,maxarea);

    }
    return maxarea;
           
}
int main(){
    //PROBLEM STATEMENT
    // You are given an integer array height of length n. 
    // There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    // Find two lines that together with the x-axis form a container, such that the container contains the most water.
    // Return the maximum amount of water a container can store    

    //EXAMPLE
    // Input: height = [1,8,6,2,5,4,8,3,7]
    // Output: 49
    // Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
    // In this case, the max area of water (blue section) the container can contain is 49.    
    vector<int>height{1,8,6,2,5,4,8,3,7};
    cout<<"the max area to hold is "<<maxArea(height);
}