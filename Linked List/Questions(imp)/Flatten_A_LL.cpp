#include<iostream>
#include<vector>
using namespace std;
//https://www.geeksforgeeks.org/flattening-a-linked-list/
class Node {
        public:
        int data;
        Node* next;
        Node*bottom;

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
Node*merge(Node*a,Node*b){
        if(!a){ 
                return a;
        }
        if(!b){
                return b;
        }

        Node*ans=0;
        if(a->data < b->data){
                ans=a;
                a->bottom=merge(a->bottom,b);
        }else{
                ans=b;
                b->bottom=merge(a,b->bottom);
        }
        return ans;
}

Node* flatten(Node*root){
        if(!root){
                return 0;
        }
        Node*MergedHead=merge(root,flatten(root->next));
        return MergedHead;
}
int main(){
        return 0;
    
}