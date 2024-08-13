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
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        //approach 1
        // if(root==NULL){
        //     return NULL;
        // }

        // //1.search for p and q
        // if(root->val==p->val){
        //     return p;
        // }
        // if(root->val==q->val){
        //     return q;
        // }

        // TreeNode*leftans=lowestCommonAncestor(root->left,p,q);
        // TreeNode*rightans=lowestCommonAncestor(root->right,p,q);
        // //2.check for 3 cases:
        // //case1:p and q are part both right abd left subtree
        // if(leftans!=NULL && rightans!=NULL){
        //     return root;
        // }
        // //case2:p and q are in left subtree only
        // else if(leftans!=NULL && rightans==NULL){
        //     return leftans;
        // }
        // //case 3:p and 1 are in right subtree only
        // else if(leftans==NULL && rightans!=NULL){
        //     return rightans;
        // }else{
        //     //p and q not found
        //     return NULL;
        // }

        //approach 2
        //base case
        if(root==NULL){
            return NULL;
        }

        //4 cases
        //1->p and q both samller that root->data
        if(root->data >p->data && root->data>q->data){
            //q and q are in left subtree
            return lowestCommonAncestor(root->left,p,q);
        }
        //2->p and q both are greater than root->data
        if(root->data < p->data && root->data < q->data){
            return lowestCommonAncestor(root->right,p,q);
        }
        //3->case 3 and 4 
        return root;
       
        
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
int main(){
    //input->[-10,-3,0,5,9]
    int inorder[]={-10,-3,0,5,9};
    int start=0;
    int end=4;

    Node*root=bstUsingInorder(inorder,start,end);

    cout<<"level order traversal after creating bst using inorder"<<endl;
    levelOrderTraversal(root);

    //lca of bst if p=-10 and =-3 should be -10
    Node*p=new Node(-10);
    Node*q=new Node(-3);
    Node*Ans=lowestCommonAncestor(root,p,q);
    cout<<"lowest common ancestor bst is :"<<Ans->data<<endl;



	  
}