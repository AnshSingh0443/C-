#include<iostream>
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

        //TODO: Write a destrcutor to delete a node
        ~Node() {
                //write your code here
                cout << "Node with value: " << this->data << "deleted" << endl;
        }
};

//I want to insert a node right at the head of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {
        //check for Empty LL
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
        }
        else {
                //step1:
                Node* newNode = new Node(data);
                //step2:
                newNode -> next = head;
                //step3:
                head = newNode;
        }


}
//I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node* &head,Node* &tail, int data) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }
        //step1: creatae a node
        Node* newNode = new Node(data);
        //step2: connect woth tail ndoe
        tail->next = newNode;
        //step3: update tail;
        tail = newNode;
}
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

Node * mergeLists(Node* &head1,Node* &head2){
    Node*mergeHead=new Node(-1);
    Node*temp3=mergeHead;

    Node*temp1=head1;
    Node*temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data>temp2->data){
            temp3->next=temp2;
            temp3=temp3->next;
            Node* forward=temp2->next;
            temp2->next=NULL;
            temp2=forward;
        }else{
            temp3->next=temp1;
            temp3=temp3->next;
            Node* forward=temp1->next;
            temp1->next=NULL;
            temp1=forward;
        }
    }
    while(temp1){
        temp3->next=temp1;
        temp3=temp3->next;
        Node* forward=temp1->next;
        temp1->next=NULL;
        temp1=forward;
    }
    while(temp2){
        temp3->next=temp2;
        temp3=temp3->next;
        Node* forward=temp2->next;
        temp2->next=NULL;
        temp2=forward;

    }
    //remove dummy node
    temp3=mergeHead;
    mergeHead=mergeHead->next;
    temp3->next=NULL;
    
    return mergeHead;
}

int main(){
    Node* head1=new Node(10);
    Node* second1=new Node(10);
    Node* third1=new Node(20);
    Node* fourth1=new Node(20);
    Node* fifth1=new Node(30);
    

    head1->next=second1;
    second1->next=third1;
    third1->next=fourth1;
    fourth1->next=fifth1;
    fifth1->next=NULL;

    cout<<"the first list is:-> ";
    print(head1);

    Node* head2=new Node(20);
    Node* second2=new Node(30);
    Node* third2=new Node(50);
    Node* fourth2=new Node(50);
    Node* fifth2=new Node(90);
    

    head2->next=second2;
    second2->next=third2;
    third2->next=fourth2;
    fourth2->next=fifth2;
    fifth2->next=NULL;
    cout<<endl;
    cout<<"the second list is:-> ";
    print(head2);
    cout<<endl;

    cout<<"printing merged list:-> ";

    Node*resHead=mergeLists(head1,head2);
    print(resHead);



}