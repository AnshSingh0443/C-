#include<iostream>
#include<unordered_map>
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

bool checkCircular(Node* head){
    unordered_map<Node*,bool>visited;
    Node* temp = head;
    while(temp!=NULL){
        if(visited.find(temp) != visited.end()){
            visited[temp] = true;
        }
        else{
            return false;
        }
        temp = temp->next;
    }
    return true;
}
int main(){

    return 0;
}