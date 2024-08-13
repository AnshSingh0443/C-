
 // https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * 
 * };
 */

// class compare {
//     public:
//     bool operator()(ListNode*a,ListNode*b){
//         return a->val > b->val;
//     }
// };
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         //k->no of lists
//         int k=lists.size();

//         //create minheap
//         priority_queue<ListNode*,vector<ListNode*>,compare>minheap;
//         //step 1
//         //first k elements ko minheap me push
//         //first elements of each list
//         if(k==0){
//             return NULL;
//         }
//         else{
//             for(int i=0;i<k;i++){
//                 if(lists[i]!=NULL){
//                     minheap.push(lists[i]);
//                 }
//             }
//         }

//         //ans linked list
//         ListNode* head=NULL;
//         ListNode* tail=NULL;


//         //step 2:jabb tak min heap is not empty
//         //top->elemnent in heap smallest
//         while(!minheap.empty()){
//             ListNode*temp=minheap.top();
//             //pop from min  heap
//             minheap.pop();

//             //2.1 top is the first elemnt
//             if(head==NULL){
//                 head=temp;
//                 tail=temp;
//                 //push new if it exists
//                 if(tail->next!=NULL){
//                     minheap.push(tail->next);
//                 }
//             }
//             else{
//                 //not the first element
//                 tail->next=temp;
//                 tail=temp;
//                 //push new if it exists
//                 if(tail->next!=NULL){
//                     minheap.push(tail->next);
//                 }

//             }
//         }

//         return head;

        
//     }
// };