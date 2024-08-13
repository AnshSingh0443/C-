
#include<iostream>
#include<vector>
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

    void solve(Node* root, int targetSum,vector<int>&path,int &currSum,vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }
        //leaf node
        if(root->left==NULL && root->right==NULL){
            //include node in path
            path.push_back(root->data);
            currSum += root->data;
            //check for target sum
            if(currSum == targetSum) {
                ans.push_back(path);
            }
            //exclude 
            path.pop_back();
            currSum -= root->data;
            return;
        }
        //include curr node
        path.push_back(root->data);
        currSum += root->data;

        solve(root->left, targetSum,path, currSum ,ans);
        solve(root->right, targetSum,path, currSum,ans);

        //backltrack
        path.pop_back();
        currSum -= root->data;

    }
    vector<vector<int>> pathSum(Node* root, int targetSum) {
        //to save all correct paths
        vector<vector<int>>ans;
        //to save current path
        vector<int>path;
        int currSum=0;
        solve(root,targetSum,path,currSum,ans);

        return ans;

    }


int main(){
    Node* root = NULL;
	root = buildTree();
   
    vector<vector<int>>ans=pathSum(root,22);


   
}