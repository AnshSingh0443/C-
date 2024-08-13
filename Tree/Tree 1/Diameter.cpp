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
    int maxDepth(Node* root) {
        if(root == NULL) 
		return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }
    int diameterOfBinaryTree(Node* root) {
        if(root == NULL) 
        return 0;

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left) + 1 + maxDepth(root->right);
        int ans = max(op1, max(op2, op3));
        return ans ;
    }
int main(){
    Node* root = NULL;
	root = buildTree();

    cout<<diameterOfBinaryTree(root);


   
}





