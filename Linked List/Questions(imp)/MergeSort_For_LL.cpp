#include <iostream>
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
void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
}
Node* getmiddle(Node* &head){

    //linked list is empty
    // if(head==NULL){
    //     cout<<"linked list is empty"<<endl;
    // }
    // //single node in LL
    // if(head->next==NULL){
    //     return head;
    // }
    //no of node >1

    Node* slow=head;
    Node* fast=head->next;
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

Node* MergeListalgo(Node* head){
    if(head==0||head->next==0){
        return 0;
    }
    //divide list into halves using mid
    //step 1:->find middle of the linked list
    Node*mid=getmiddle(head);

    Node*left=head;
    Node*right=mid->next;
    mid->next=0;
 

    // we have created two lists left and right

    //step 2-> we divide the lists into singular nodes as singular nodes are sorted
    left=MergeListalgo(left);
    right=MergeListalgo(right);

    //step3->merge the sorted linked lists
    Node*mergedList=mergeLists(left,right);
    

    return mergedList;

    
}

int main(){
    Node* head=new Node(10);
    Node* second=new Node(3);
    Node* third=new Node(5);
    Node* fourth=new Node(1);
    Node* fifth=new Node(20);
    

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;

    cout<<"Printing LL before sorting:-> ";
    print(head);

    cout<<endl;

    cout<<"Printing LL after sorting:-> ";

    Node*MergedHead=MergeListalgo(head);
    cout<<"mergedhead->"<<MergedHead->data;
    print(MergedHead);
}