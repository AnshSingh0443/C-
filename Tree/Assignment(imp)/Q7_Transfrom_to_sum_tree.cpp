#include <iostream>
#include<queue>
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

int sum(Node *root){
    //base case
    if(!root){
        return 0;
    }
    //all leaf node data=0
    if(!root->left && root->right){
        //save original so that upper node can use it to change itself
        int temp=root->data;
        root->data=0;
        //return karo original 
        return temp;
    }
    int leftsum=sum(root->left);
    int rightsum=sum(root->right);
    int temp=root->data;
    root->data=leftsum+rightsum;
    return (root->data + temp);
}
void Sumtree(Node*root){
    sum(root);
}

 
int main() {
	Node* root = NULL;

	root = buildTree();
    cout<<"tree :"<<endl;
	levelOrderTraversal(root);
    Sumtree(root);
    cout<<"sumtree :"<<endl;
	levelOrderTraversal(root);

    //input->10 -2  8  -1 -1 -4 -1 -1 6 7 -1 -1 5 -1 -1
        // 10
        // -2 6
        // 8 4 7 5
    //output->sumtree :
        // 28
        // 12 12
        // 0 0 0 0

	




	return 0;
}