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

//approach 1
Node* knodeformend(int k,Node* &head){
    Node*temp=head;
    int length=findLength(head);
    int posFromStart=length-(k+1);//k+1->as given pos is oth indexed
    while(posFromStart>0){
        temp=temp->next;
        posFromStart--;
    }
    return temp;
}
//approach 2->recursion
void solve(int &k,Node* head,int &ans){
    if(head==NULL){
        return;
    }
    solve(k,head->next,ans);
    //while returning/backtarcking we actually traverse the linked list backwards
    if(k==0){
        ans=head->data;
    }

    k--;

}
int kth_node_from_end(int k,Node* head){
    int ans=-1;
    solve(k,head,ans);
    return ans;
    
}
int main(){
    Node* head=new Node(3);
    Node* second=new Node(2);
    Node* third=new Node(1);
    head->next=second;
    second->next=third;
    third->next=NULL;

    print(head);

    cout<<endl<<"length of ll is->"<<findLength(head);
    int k=0;
    Node*res=knodeformend(k,head);

    cout<<endl;

    cout<<k<<"th node form the end is"<<res->data<<endl;

    cout<<"the "<<k<<" node from the end is "<<kth_node_from_end(k,head);

    
}