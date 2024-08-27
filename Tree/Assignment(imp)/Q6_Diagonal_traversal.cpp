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

vector<int>diagonal(Node*root){
    //approach 1->using distance d initially 0 when we go left->+1 and when we go right->do nothing
    //use map to store all nodes with key as distance map<int,vector<int>> ie sorted 0->... then 1->... and so on
    //then print traveresal usinng this map

    //approach 2->use level order and at each node ->print all the right sub nodes
    // while also checking if there exists a left push it onto queue
    vector<int>ans;

    if(!root){
        return ans;
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        while(temp){
            ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            temp=temp->right;
        }

    }
    cout<<"traversal:"<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    return ans;
}

int main(){
    //GFG
    Node*root=buildTree();
    diagonal(root);
    
}