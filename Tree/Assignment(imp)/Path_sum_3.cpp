#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
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
int ans=0;
void solve(Node*root,long long sum){
        //base case
        if(!root) return;
        //another->if sum becomes equal to the node->val then path exists 
        if(sum==root->data){
            //path+1
            ++ans;
        }
        //make call for left and right with updated sum=sum-root->val(we visited this node)
        solve(root->left,sum-root->data);
        solve(root->right,sum-root->data);
        
}
int pathSum(Node* root, long long targetSum) {
        if(root){
            solve(root,targetSum);
            //since ist given that path is not resticted to root to leaf we need to call the function for each node as root
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);

            
        }
        return ans;
        
}
int main(){
    Node* root = NULL;

	root = buildTree();

    cout<<"level order traversal of tree"<<endl;
    levelOrderTraversal(root);
    int targetSum=8;
    //input tree:10,5,3,3,-1,-1,-2,-1,-1,2,-1,1,-1-1,-3,-1,11,-1,-1

    cout<<pathSum(root,targetSum);

}