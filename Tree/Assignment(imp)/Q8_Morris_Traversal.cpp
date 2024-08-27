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

    vector<int> MorrisinorderTraversal(Node* root) {
        //MORRIS INORDER TRAVERSAL->we will use the right link of nodes to estalish a temp link between the node and their inorder predecessor and remove it after its use

        vector<int>ans;
        Node*curr=root;
        while(curr){
            //check if left is  null if it is include curr value and move right
            if(!curr->left){
                ans.push_back(curr->data);
                curr=curr->right;
            }else{
                //left is not null
                //find inorder pred
                Node* inpred=curr->left;
                while(inpred->right!=curr && inpred->right){
                    inpred=inpred->right;
                }

                //if right is nul go left after establishing a link bwteen curr and inpred
                if( inpred->right==NULL){
                    inpred->right=curr;
                    curr=curr->left;
                }else{
                    //left is already visited , go right after visiting curr node while removeing the link
                    inpred->right=NULL;
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return ans;
        
    }



void inorderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return ;
	}

	//LNR
	inorderTraversal(root->left);
	cout << root -> data << " ";
	inorderTraversal(root->right);
}



int main() {
	Node* root = NULL;

	root = buildTree();
	inorderTraversal(root);
	




	return 0;
}