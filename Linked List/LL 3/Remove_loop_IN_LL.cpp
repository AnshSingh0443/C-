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
void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
}
Node* Remove_Loop(Node* &head){
    if(head==NULL){
        cout<<"linked list is empty "<<endl;
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    Node*prev=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==fast){
            //reset slow to head 
            slow=head;
            break;
        }
    }
    if(fast==NULL){
        cout<<"no loops"<<endl;
        return NULL;
    }


   while(slow!=fast){
        prev=fast;
        slow=slow->next;
        fast=fast->next;
   }
   //prev is trailing fast now when fast and slow meet at starting node of loop
   // prev will be at the point where node can be disconnected ie ending node of the loop just before the starting node
   prev->next=NULL;//->node disconnect->loop removed
    return head;
}
int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);
    Node* sixth=new Node(60);
    Node* seventh=new Node(70);
    Node* eighth=new Node(80);
    Node* ninth=new Node(90);


    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;
    seventh->next=eighth;
    eighth->next=ninth;
    ninth->next=fifth;//loop is created

    Remove_Loop(head);
    //print after removing the loop
    print(head);
}