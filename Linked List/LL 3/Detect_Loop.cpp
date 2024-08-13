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

//imp->Floyd cycle detection
// slow and fast pointer/ tortoise algo
// slow can onlu jump 1 step
// fast can only jump 2 steps
// and slow can only jump if fast has completed its 2 steps
// in case of loop slow and fast both will point at the same node after a while and if fast reaches the end-<null no loop exists
// how?-> with every pass the dis between fast and gets reduced by one so at one point if loop exists they will meet
bool Detect_Loop(Node* &head){
    if(head==NULL){
        cout<<"linked list is empty "<<endl;
        return false;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==fast){
            //loop exists
            return true;
        }
    }
    //fast becomes null
    //no loop exists
    return false;

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
    // ninth->next=fifth;
    ninth->next=NULL;
    // a linked list with loop is created

    // print(head);
    cout<<endl;
    bool res=Detect_Loop(head);
    cout<<res;
    // if(res){
    //     cout<<"loop exists";
    // }
    // else if(!res){
    //     cout<<"loop does not exist";
    // }


}