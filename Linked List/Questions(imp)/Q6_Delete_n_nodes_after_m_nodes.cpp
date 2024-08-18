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

void Linkdelete(Node*head,int m,int n){
    if(!head){
        return;
    }
    Node*it=head;
    //skip m nodes
    for(int i=0;i<m-1;i++){
        if(!it){
            return;
        }
        it=it->next;
    }
    //it->would be mth node
    if(!it){
        return;
    }
    Node* MthNode=it;
    it=MthNode->next;
    //delete n nodes
    for(int i=0;i<n;i++){
        if(!it){
            break;
        }
        Node*temp=it->next;//save link
        delete it;
        it=temp;
    }
    MthNode->next=it;
    Linkdelete(it,m,n);
}

int main(){

}