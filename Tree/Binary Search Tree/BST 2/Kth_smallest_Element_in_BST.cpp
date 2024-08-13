#include <iostream>
#include<queue>
using namespace std;

class Node {
        public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
                this->data = data;
                this->left = NULL;
                this->right = NULL;
        }
};


Node* insertIntoBST(Node* root, int data) {

        if(root == NULL) {
                //this is the first node we have to create
                root = new Node(data);
                return root;
        }

        //no the first node 

        if(root-> data > data) {
                //insert in left
                root->left = insertIntoBST(root->left, data);
        }
        else {
                //insert into right
                root->right = insertIntoBST(root->right, data);
        }
        return root;
}

void takeInput(Node* &root) {
        int data;
        cin >> data;

        while(data != -1) {
                root = insertIntoBST(root, data);
                cin >> data;
        }
}
void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
		
		
	}
}
int kthSmallest(Node* root, int& k) {
        if(root==NULL){
            return -1;
        }
        //inorder traverse karte karte after L N (check if k==0) R
        //where k==0 that node is kth smallest element

        //left 
        int leftans=kthSmallest(root->left,k);
        if(leftans!=-1){
            return leftans;
        }
        //Node->root
        k--;
        if(k==0){
            return root->data;
        }
        int rightans=kthSmallest(root->right,k);
        return rightans;
        
}
int main() {
	  Node* root = NULL;
	  cout << "Enter the data for Node " << endl;
	  //tree input=10 20 5 11 17 2 4 8 6 25 -1
	  takeInput(root);
	  cout << "Printing the tree" << endl;
	  levelOrderTraversal(root);
	  cout << endl;
      int k=3;
      //kth smallest should be 5
      cout<<k<<"th smallest element in the bst is "<<kthSmallest(root,k)<<endl;
}