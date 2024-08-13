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

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

Node* reverseKGroup(Node* &head, int k) {

    if(head==NULL){
        cout<<"linked list is empty";
        return NULL;
    }
    //single node in LL
    if(head->next==NULL){
        return head;
    }
    //if k>length of LL
    int len=findLength(head);
    if(k>len){
        return head;
    }

    //no of node > 1

    // slove 1 case-> reverse first k nodes of LL rest->recursion
    Node*prev=NULL;
    Node*curr=head;
    Node*forward=curr->next;
    int count=0;//keeps track of k nodes
    while(count < k){
        //forward pointer helps in keeping the link to linked list 
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }


    //R.R
    if(forward!=NULL){
        //connect the tail of the first k reverse list to the head of the next k reverse lists
        head->next=reverseKGroup(forward,k);//forward will now point at the next part of LL
    }


    // return the head/starting node of modified list
    return prev;
        
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
    print(head);
    cout<<endl;

    Node*prev=reverseKGroup(head,3);

    print(prev);

}