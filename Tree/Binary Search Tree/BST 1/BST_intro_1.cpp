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

void preOrderTraversal(Node* root) {
	//NLR
	if(root == NULL)
		return;

	cout << root->data << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
	//LNR
	if(root == NULL)
		return;

	inOrderTraversal(root->left);
	cout << root->data << " ";
	inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	//LRN
	if(root == NULL)
		return;

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << " ";
}

//assuming there are only unique values in tree
Node* findNodeInBST(Node* root, int target) {
	///base case
	if(root == NULL) {
		return NULL;
	}

	if(root->data == target) 
		return root;
//assuming there are only unique values in tree
	// Node* leftAns = false;
	// Node* rightAns = false;
	
	if(target > root->data) {
		//right subtree me search karo
		return findNodeInBST(root->right,  target);
	}
	else {
		return findNodeInBST(root->left,  target);
	}
}

int minVal(Node* root) {
	Node* temp = root;
	if(temp == NULL) {
		return -1;
	}

	while(temp -> left != NULL) {
		temp = temp ->left;
	}
	return temp -> data;
}

int maxVal(Node* root) {
	Node* temp = root;
	if(temp == NULL) {
		return -1;
	}

	while(temp -> right != NULL) {
		temp = temp ->right;
	}
	return temp -> data;
}



Node* deleteNodeInBST(Node* root, int target) {
	
	//base cae
	if(root == NULL ) {
		return NULL;
	}
//cout << "Request recieved for " >> root->data << " with target" << target << endl;
	if(root->data == target) {
		//isi ko delete krna h 
		//4 cases 
		if(root->left == NULL && root->right == NULL) {
			//leaf node
			//delete root;
			return NULL;
		}
		else if(root->left == NULL && root->right != NULL) {
			Node* child = root->right;
			//delete root;
			return child;
		}
		else if(root->left != NULL && root->right == NULL) {
			Node* child  = root->left;
			//delete root;
			return child;
		}
		else {
			//both child
			//find inorder predecessor inb left subtree
			int inorderPre = maxVal(root->left);
			//replace root->data value with inorder predecessor
			root->data = inorderPre;
			//delete inorder predecessor from left subtree
			root->left = deleteNodeInBST(root->left,inorderPre);
			return root;
			
		}
		
	}
	else if(target > root -> data) {
		//right jana chahiye
		root->right =  deleteNodeInBST(root->right, target);
	}
	else if(target < root->data) {
		//left jana chahioye
		root->left = deleteNodeInBST(root->left, target);
	}
	return root;
}

Node* Inorder_Successor(Node* root,Node * x){
	//Inorder succ->node x se just bada
	Node*succ=0;
	Node*curr=root;

	while(curr){
		if(curr->data > x->data){
			succ=curr;
			//try to find lesser
			curr=curr->left;
		}
		else{
			curr=curr->right;
		}
	}
	return succ;
}

Node* Inorder_predecessor(Node* root,Node * y){
	//Inorder succ->node x se just chota
	Node*pred=0;
	Node*curr=root;

	while(curr){
		if(curr->data < y->data){
			pred=curr;
			//try to find bigger
			curr=curr->right;
		}
		else{
			curr=curr->left;
		}
	}
	return pred;
}


int main() {
	  Node* root = NULL;
	  cout << "Enter the data for Node " << endl;
	  //tree input=10 20 5 11 17 2 4 8 6 25 -1
	  takeInput(root);
	  cout << "Printing the tree" << endl;
	  levelOrderTraversal(root);
	  cout << endl;


	  cout<<"finding inorder succ of 4"<<endl;
	  Node*x=new Node(4);
	  Node*Res=Inorder_Successor(root,x);
	  cout<<":"<<Res->data<<endl;


	  cout<<"finding inorder pred of 5"<<endl;
	  Node*y=new Node(5);
	  Node*res=Inorder_predecessor(root,y);
	  cout<<":"<<res->data<<endl;

	//   cout << "Printing Inorder: " << endl;
	//   inOrderTraversal(root);
	//   cout << endl;
	//   cout << "Printing Preorder: " << endl;
	//   preOrderTraversal(root);
	//   cout << endl;
	//   cout << "Printing Postorder: " << endl;
	//   postOrderTraversal(root);

	// bool ans  = findNodeInBST(root,155);
	// cout << "present or not : " << ans << endl;
	// cout << endl <<" Minimum value: " << minVal(root) << endl;
	// cout << endl << "Maximum value: " << maxVal(root) << endl;

	// root = deleteNodeInBST(root, 100);
	// levelOrderTraversal(root);
	
  return 0;
}