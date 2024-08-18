#include<iostream>
#include<vector>

using namespace std;
//https://leetcode.com/problems/merge-nodes-in-between-zeros/
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    ListNode* mergeNodes(ListNode* head) {
        //using slow and fast pointer
        //fast->will calulate sum till it reaches a 0
        //slow will chanage the node val to sum  
        //lastnode->follow slow and when fast becomes nulll
        //deatach->lastnode->next=0;

        ListNode*slow=head;
        ListNode*fast=head->next;
        ListNode*lastnode=NULL;
        int sum=0;
        while(fast){
            if(fast->val!=0){
                sum=sum+fast->val;
            }else{
                //fast->val==0
                //val=sum ka node banao via slow
                slow->val=sum;
                lastnode=slow;
                slow=slow->next;
                //reset sum
                sum=0;

            }
            fast=fast->next;
        }
        //deatch
        ListNode*temp=lastnode->next;
        lastnode->next=0;
        //delete the rest
        while(temp){
            ListNode*nxt=temp->next;
            delete(temp);
            temp=nxt;
        }

        return head;

        

        
    }


int main(){

}