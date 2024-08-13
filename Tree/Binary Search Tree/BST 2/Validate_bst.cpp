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
//creting bst using sorted  array or inorder traversal
Node* bstUsingInorder(int inorder[], int s, int e) {
	//base case
	if(s > e) {
		return NULL;
	}

	int mid = (s+e)/2;
	int element = inorder[mid];
	Node* root = new Node(element);

	root->left = bstUsingInorder(inorder, s, mid-1);
	root->right = bstUsingInorder(inorder, mid+1, e);

	return root;
	
}
bool solve(Node* root, long long int lb, long long int ub) {
    //base case
    if(root == NULL)
        return true;
    
    if(root->data > lb && root->data < ub) {
        bool leftAns = solve(root->left, lb, root->data);
        bool rightAns = solve(root->right, root->data, ub);
        return leftAns && rightAns;
    }
    else {
        return false;
    }

}
bool isValidBST(Node* root) {
        long long int lowerBound = -4294967296 ;
        long long int upperBound = 4294967296;
        bool ans  = solve(root, lowerBound, upperBound );
        return ans;
}
int main(){
    //input->[-10,-3,0,5,9]
    int inorder[]={-10,-3,0,5,9};
    int start=0;
    int end=4;

    Node*root=bstUsingInorder(inorder,start,end);

    cout<<"level order traversal after creating bst using inorder"<<endl;
    levelOrderTraversal(root);

    //check if the bst is  valid or not
    bool ans=isValidBST(root);
    if(ans){
        cout<<"above tree is a bst"<<endl;
    }else{
        cout<<"not a bst"<<endl;
    }



	  
}