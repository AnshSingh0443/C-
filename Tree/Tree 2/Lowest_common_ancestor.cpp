
#include<iostream>
using namespace std;

class Node{
	public:
	int data;	
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};



Node* buildTree() {
	int data; 
	cout << "Enter the data: " << endl;
	cin >> data;

	if(data == -1) {
		return NULL;
	}

	//Step A , B and C
	Node* root = new Node(data);

	cout << "Enter data for left part of " << data << " node " << endl;
	root->left = buildTree();
	
	cout << "Enter data for right part of " << data << " node " << endl;
	root-> right = buildTree();

	return root;
	
}
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(root==NULL){
            return NULL;
        }

        //1.search for p and q
        if(root->data==p->data){
            return p;
        }
        if(root->data==q->data){
            return q;
        }

        Node*leftans=lowestCommonAncestor(root->left,p,q);
        Node*rightans=lowestCommonAncestor(root->right,p,q);
        //2.check for 3 cases:
        //case1:p and q are part both right abd left subtree
        if(leftans!=NULL && rightans!=NULL){
            return root;
        }
        //case2:p and q are in left subtree only
        else if(leftans!=NULL && rightans==NULL){
            return leftans;
        }
        //case 3:p and 1 are in right subtree only
        else if(leftans==NULL && rightans!=NULL){
            return rightans;
        }else{
            //p and q not found
            return NULL;
        }
    }





int main(){
    Node* root = NULL;
	root = buildTree();
    Node*p=new Node(60);
    Node*q=new Node(40);

    Node *res=lowestCommonAncestor(root,p,q);

    cout<<res->data;


   
}