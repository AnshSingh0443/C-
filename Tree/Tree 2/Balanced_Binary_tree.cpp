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
int Height(Node* root) {
        if(root == NULL) 
		return 0;

        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
}
bool isBalanced(Node* root) {
        //base case
        if(root==NULL){
            return true;
        }

        //ek case solve
        int leftHeight=Height(root->left);

        int RightHeight=Height(root->right);

        int diff=abs(leftHeight-RightHeight);

        bool ans=(diff<=1);

        //recursion
        bool leftans=isBalanced(root->left);
        bool rightans=isBalanced(root->right);

        if(ans && leftans && rightans)
            return true;
        else
            return false;
        
}
int main(){
    Node* root = NULL;
	root = buildTree();

    cout<<isBalanced(root);


   
}