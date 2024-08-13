#include<iostream>
#include<vector>
#include<stack>

using namespace std;
//brute force
int largestRectangleArea(vector<int>& heights) {
        int area=0;
        int maxArea=0;
        //brute force
        for(int i=0;i<heights.size();i++){
            int length=heights[i];
            int width=1;

            //extend left
            int j=i-1;
            while(j>=0 && heights[j]>=heights[i]){
                width=width+1;
                j--;
            }
            j=i+1;
            //extend right
            while(j<=heights.size()-1 && heights[j]>=heights[i]){
                width=width+1;
                j++;
            }

            area=length*width;
            maxArea=max(area,maxArea);


            
        }
        return maxArea;
        
}

//get next smaller
vector<int>nextSmaller(vector<int>&heights){
    stack<int> st;
   
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
    stack<int> st;
    st.push(-1);
    vector<int>ans(heights.size());
    for(int i=0;i<=heights.size()-1;i++){
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
int largestRectangleArea2(vector<int>& heights) {
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
int main(){
    vector<int>heights{2,1,5,6,2,3};
    int ans=largestRectangleArea2(heights);
    cout<<ans;

}