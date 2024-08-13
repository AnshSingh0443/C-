#include <iostream>
#include<queue>
#include<vector>
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
    void Inorder_Traversal(Node*root,vector<int>&inorder){
        if(root==NULL){
            return;
        }
        //left
        Inorder_Traversal(root->left,inorder);
        //node
        inorder.push_back(root->data);
        //right
        Inorder_Traversal(root->right,inorder);
    }
    bool findTarget(Node* root, int k) {
        //1.store inorder
        vector<int>inorder;
        Inorder_Traversal(root,inorder);

        //apply 2 pointers
        int s=0;
        int e=inorder.size()-1;

        while(s<e){
            int sum=inorder[s]+inorder[e];
            if(sum==k){
                return true;
            }
            else if(sum>k){
                e--;
            }
            else if(sum<k){
                s++;
            }
        }

        return false;


        
    }
int main() {
	  Node* root = NULL;
	  cout << "Enter the data for Node " << endl;
	  //tree input=10 20 5 11 17 2 4 8 6 25 -1
	  takeInput(root);
	  cout << "Printing the tree" << endl;
	  levelOrderTraversal(root);
	  cout << endl;
      int target=46;//can be made by 11+2 so should return true//we can not make 46 return false
      bool ans =findTarget(root,target);
      if(ans){
        cout<<"we can make "<<target<<endl;
      }else{
        cout<<"no two elems such that they make "<<target<<endl;
      }

}