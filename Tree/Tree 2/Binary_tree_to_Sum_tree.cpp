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

int Sum_Tree(Node*root){
    //base case
    if(root==NULL){
        return 0;
    }

    //1.left tree se ans
    int left=Sum_Tree(root->left);

    //2.right tree se ans
    int right=Sum_Tree(root->right);

    //3.root->data change=left+right+root->data
    root->data=root->data+left+right;

    return root->data;
}

int main(){
    Node* root = NULL;
	root = buildTree();

    cout<<Sum_Tree(root)<<" ";

   
}