#include<iostream>
#include<unordered_map>
#include<vector>

//https://leetcode.com/problems/copy-list-with-random-pointer/

using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
    Node*Helper(Node*head,unordered_map<Node*,Node*>&mp){
        //step  1 first create a simple ll with no random
        if(head==NULL){
            return 0;
        }

        //create new LL hread
        Node*newHead=new Node(head->val);
        //save enrty of oldnode to newnode
        mp[head]=newHead;
        newHead->next=Helper(head->next,mp);
        //why map->so that we can assign random pts while  returning
        if(head->random){
            //point the newhead random to corresponding entry in map
            //agar oldhead->random points to x(oldhead) 
            //then newhead->random should also point to x but in the new ll
            newHead->random=mp[head->random];
        }

        return newHead;

    }
    Node* copyRandomList(Node* head) {
        //METHOD 1
        // unordered_map<Node*,Node*>mp;
        // return Helper(head,mp);

        //METHOD 2
        //step 1 create a LL such that (old node)A->A`(new node)
        if(head==NULL){
            return 0;
        }

        Node*it=head;
        while(it){
            Node*ClonedNode=new Node(it->val);
            ClonedNode->next=it->next;
            it->next=ClonedNode;
            it=it->next->next;
        }
        //linked list:7->7->13->13->11->11->10->10->1->1->null  where first node is old 
        //and second node  is new

        //step 2 assign random pointers
        it=head;
        while(it){
            Node*ClonedNode=it->next;
            ClonedNode->random=it->random? it->random->next:nullptr;
            it=it->next->next;
        }

        //step 3:detach list
        it=head;
        Node*ClonedHead=it->next;
        while(it){
            Node*ClonedNode=it->next;
            it->next=it->next->next;
            if(ClonedNode->next){
                ClonedNode->next=ClonedNode->next->next;
            }
            it=it->next;
        }
        return ClonedHead;
    }

int main(){
    return 0;

}