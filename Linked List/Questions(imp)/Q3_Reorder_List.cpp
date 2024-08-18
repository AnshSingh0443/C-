#include<iostream>
#include<vector>

using namespace std;
//https://leetcode.com/submissions/detail/1360397356/
  
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
    void reorderList(ListNode* head) {
        //brute force
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return;
        }
        // ListNode*it=head;
        // while(it->next){
        //     ListNode*PrevLast=head;
        //     while(PrevLast->next->next){
        //         PrevLast=PrevLast->next;
        //     }
        //     if(PrevLast==it){
        //         break;
        //     }
           
        //     PrevLast->next->next=it->next;
        //     it->next=PrevLast->next;;
        //     PrevLast->next=NULL;
            

        //     if(it->next->next==NULL){
        //         break;
        //     }

        //     it=it->next->next;
        
        // }

        //USING FAST AND SLOW POINTERS
         // base case : linkedlist is empty
        if (!head) return;
        
        // finding the middle with the help of two pointer approach
        ListNode *tmp = head, *half = head, *prev = NULL;
        while (tmp->next && tmp->next->next) {
            tmp = tmp->next->next;
            half = half->next;
        }
        
        // adding one bit in case of lists with even length
        if (tmp->next) half = half->next;
        
        // Now reverse the second half
        while (half) {
            tmp = half->next;
            half->next = prev;
            prev = half;
            half = tmp;
        }
        half = prev;
        
        // After reversing the second half, let's merge both the halfes
        while (head && half) {
            tmp = head->next;
            prev = half->next;
            head->next = half;
            half->next = tmp;
            head = tmp;
            half = prev;
        }
        
        // Base case : closing when we had even length arrays
        if (head && head->next) head->next->next = NULL;

        

        
    }

int main(){

}