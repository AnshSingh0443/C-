#include<iostream>
#include<vector>
#include<stack>

using namespace std;

    vector<int> nextLargerNodes(ListNode* head) {
        //1.save the whole inked list in an array

        vector<int>arr;
        stack<int>st;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        vector<int>ans(arr.size(),0);

        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
                int elems=st.top();
                st.pop();
                //vo elems jo stack me hai and are sammler than arr[i]-->arr[i] will be there next greater
                ans[elems]=arr[i];
                 // agar alg se ans array nahi banana hai toh same array me change
                 // arr[elems]=arr[i]
            }

            st.push(i);
        }
        //ab sttack mme wahoi elem hai jinka koi next greater elem nahi hai toh usnke liye ->0
        // agar alg se ans array nahi banana hai toh same array me change
        // while(!st.empty()){
        //     int elem=st.top();
        //     st.pop();
        //     ans[elem]=0;
        // }

        return ans;
        
    }

int main(){

}