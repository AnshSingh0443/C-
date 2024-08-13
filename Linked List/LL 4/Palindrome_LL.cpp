#include<iostream>
#include<vector>
using namespace std;
class Node {
        public:
        int data;
        Node* next;

        Node() {
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }
};

// approach 1->create a new reverse linked list and then traverse both the orginal and reversed LL for palindrome check

// approach 2->create a array and store all the node data into the array then do palindrome check on array using pointers

//best way->T.C-<o(n)
// approach 3->find middle of LL and reverse the other half of LL after the middle node
//             keep pointers on the 2 half of the LL and then do palindrome check

Node* reverse(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=curr->next;

    while(curr!=NULL){
        forward=curr->next;;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

bool IsPalindromeLL(Node* &head){
    if(head==NULL){
        cout<<"linked list is empty";
        return true;
    }
    //single node
    if(head->next==NULL){
        cout<<"Single  node is a palindrome";
        return true;
    }
    //step  1->find middle of linked list
    Node* fast=head->next;
    Node* slow=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    //slow is pointing at the middle node of LL

    //step 2->reverse the LL after the middle node
    Node* reverseLLkaHead=reverse(slow->next);
    //join the other (reversed) halff with the left part
    slow->next=reverseLLkaHead;

    //step 3-> now compare the both halfs

    Node* temp1=head;
    Node* temp2=reverseLLkaHead;
    while(temp2!=NULL){
        if(temp1->data != temp2->data){
            return false;
        }else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }

    return true;

    
}
void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
}

int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(900);
    Node* fourth=new Node(40);
    Node* fifth=new Node(10);
   


    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;
    
    print(head);

    bool res=IsPalindromeLL(head);
    cout<<endl;

    if(res){
        cout<<"LL is a valid palindorme"<<endl;
    }else{
        cout<<"LL not a valid palindrome"<<endl;
    }

    
}