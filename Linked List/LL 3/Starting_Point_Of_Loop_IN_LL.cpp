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
Node* Starting_Node_Of_Loop(Node* &head){
    if(head==NULL){
        cout<<"linked list is empty "<<endl;
        return NULL;
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
            //reset slow to head 
            slow=head;
            break;
        }
    }

   while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
   }
    return slow;
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
    ninth->next=fifth;
    // ninth->next=NULL;
    // a linked list with loop is created


    //logic 
    // A->distance between head node and starting node of loop 
    // B->distance between starting node of loop and the node at which slow and fast pointer meet
    // C->total distance/length of loop
    // we know that [distance travelled by fast=2*distance travelled by slow](since fast has twice the speed than slow)
    // fast meet up wale node par kaise aya?
    // dis trav by [fast=A+xC+B]->(x->some no of loops run by fast before  meeting up)
    // dis trav by [slow=A+yC+B]->(y->some no of loops run by slow before meeting up)
    // so 
    // A+xC+B=2*(A+yC+b)
    // (x-2y)*C=A+B
    // let (x-2y)=k-> some no of loops run
    // K*C=A+B->k no of loops run
    // now we can say the A + B will denfinety create the loop
    // using the above exp we can say  that the distance from meetup node to starting node of loop is A
    // so we start slow from head and fast from meetup node they now jump 1 step each
    // and since the dis for both is A they will now meetup at the starting node of the loop
    Node*res=Starting_Node_Of_Loop(head);
    cout<<res->data;

}