#include<iostream>
#include<vector>
#include<stack>

using namespace std;
//https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
       //get next smaller
    vector<int>nextSmaller(vector<int>&heights){
        stack<int>st;
    
        st.push(-1);
        vector<int>ans(heights.size());
        for(int i=heights.size()-1;i>=0;i--){
            int curr=heights[i];
            while(st.top() !=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            //instead of storing no we will store index in order to calculate width
            ans[i]=st.top();
            st.push(i);
        }
        return ans;


    }
    //get prev smaller->change store index instead of elem
    vector<int> prevSmaller(vector<int>&heights){
        stack<int>st;
        st.push(-1);
        vector<int>ans(heights.size());
        for(int i=0;i<heights.size();i++){
            int curr=heights[i];
            while(st.top() !=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            //instead of storing no we will store index in order to calculate width
            ans[i]=st.top();
            st.push(i);
        }
        return ans;


    }
    //optimized soln using stack

    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev = prevSmaller(heights);

        vector<int>next = nextSmaller(heights);

        int maxArea=INT_MIN;

        for(int i=0;i<heights.size();i++){
            int l=heights[i];

            int size=heights.size();
            //make change for nextsmaller->instead if -1->put heights.sizee()->6
            if(next[i]==-1){
                next[i]=size;
            }
            int w= next[i]-prev[i]-1;

            int area=l*w;

            maxArea=max(area,maxArea);
        }
        return maxArea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            vector<int>t;
            for(int j=0;j<m;j++){
                //char to int
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }
        int area=largestRectangleArea(v[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                //update curr row value to make histrogarm 
                if(v[i][j]){
                    //agar 1 hai toh prev row ki value add kardo
                    v[i][j]+=v[i-1][j];
                }else{
                    //1 nahi hai
                    v[i][j]=0;
                }
            }
            area=max(area,largestRectangleArea(v[i]));
        }
        return area;

        
    }
};
int main(){
    return 0;
}