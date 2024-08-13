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
//1.first approach is to find the length of linked list
//   if length->odd then middle=length/2 +1
//   if length->even then middle=length/2
//   T.C->o(n)

//imp
//2.slow and fast pointer/ tortoise algo
// slow can onlu jump 1 step
// fast can only jump 2 steps
// and slow can only jump if fast has completed its 2 steps
Node* getmiddle(Node* &head){

    //linked list is empty
    if(head==NULL){
        cout<<"linked list is empty"<<endl;
    }
    //single node in LL
    if(head->next==NULL){
        return head;
    }
    //no of node >1

    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;// we dont jump directy 2 steps as it can give null pointer exception
        if(fast!=NULL){
            // we can jump again
            fast=fast->next;//2steps of fast complete
            slow=slow->next;
        }
    }

    return slow;
}
int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);
    // Node* sixth=new Node(60);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;
    // sixth->next=NULL;

    print(head);
    cout<<endl;

    Node* middle=getmiddle(head);
    cout<<middle->data;
   

}