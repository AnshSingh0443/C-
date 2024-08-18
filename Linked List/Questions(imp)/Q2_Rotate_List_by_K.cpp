#include<iostream>
#include<vector>

//https://leetcode.com/problems/rotate-list/

using namespace std;
class ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    // int findLength(ListNode* &head ){
    //     int len = 0;
    //     ListNode* temp = head;
    //     while(temp != NULL) {
    //             temp = temp->next;
    //             len++;
    //     }
    //     return len;
    // }

    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(head==NULL){
    //         return 0;
    //     }
    //     int len=findLength(head);

    //     int actualK=k%len;

    //     if(actualK==0){
    //         return head;
    //         //node need to rotate list will be same

    //     }
    //     ListNode*newLastNode=head;
    //     int newLastPos=len-actualK-1;

    //     for(int i=0;i<newLastPos;i++){
    //         newLastNode=newLastNode->next;
    //     }
    //     ListNode *newHead=newLastNode->next;
    //     newLastNode->next=NULL;

    //     ListNode*it=newHead;
    //     while(it->next){
    //         it=it->next;
    //     }
    //     it->next=head;
    //     return newHead;
        
    // }


int main(){
    return 0;

}