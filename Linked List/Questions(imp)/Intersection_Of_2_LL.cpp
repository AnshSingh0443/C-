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
Node* findIntersection(Node* &head1,Node * &head2){
        Node* a=head1;
        Node* b=head2;
        while(a->next && b->next){
               
                if(a==b){
                        return a;
                }
                a=a->next;
                b=b->next;
        }
       
    
        //if  a nd b both reach the both but are not  pointing on the same node->LL are not intersection
        if(a->next==0 && b->next==0 && a!=b){
                return 0;
        }

        if(a->next==0){
                //b is a bigger or same length LL->we find the diff in len
                int diff=0;
                while(b->next){
                        diff++;
                        b=b->next;
                }
                while(diff--){
                     
                        head2=head2->next;
                }
        }else{
                //a is a bigger LL or of the same length->find the diff
                int diff=0;
                while(a->next){
                        diff++;
                        a=a->next;
                }
                while(diff--){
                        head1=head1->next;
                }
        }
        cout<<"after shifting heads"<<endl;
        cout<<"head1->data="<<head1->data<<endl;
        cout<<"head2->data="<<head2->data<<endl;
        //logic? by cal the diff between length there heads are started accordingly 
        //now if we tarverse both linked list using head1 and head2 they will meet at the intersection point
        while(head1!=head2){
                head1=head1->next;
                head2=head2->next;
        }
       
        return head1;

}
int main(){
    //first linked list
    Node *head1=new Node(1);
    Node *second1=new Node(2);
    Node *third1=new Node(3);
    Node *fourth=new Node(4);
    Node *fifth=new Node(5);   
    head1->next=second1;
    second1->next=third1;
    third1->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;
    cout<<"Printing first LL:-> ";
    print(head1);
    cout<<endl;

    //2nd linked list
    Node* head2=new Node(1);
    Node* second2=new Node(2);
    Node* third2=new Node(3);
    head2->next=second2;
    second2->next=third2;
    third2->next=third1;//here this node is connected to the first linked list
    cout<<"Printing 2nd LL:-> ";
    print(head2);
    cout<<endl;

    //we can see that the node third2 of the 2ND LL is connected to NODE third1 of the 1ST LL making it the intersection node between third LL
    Node*res=findIntersection(head1,head2);
    cout<<"the intersection point is at node with data->"<<res->data;










}