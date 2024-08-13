#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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
    vector<vector<int>> verticalTraversal(Node* root) {
        // a map with col as key and value:(map of row as key and node value at that node in sorted(mutltiset)) 
        //basically col->{ row->[x,y,z...]}
        map<int,map<int,multiset<int>>>mapping;
        // to store vertical traversal
        vector<vector<int>>ans;

        //queue for level order traversal->we need to store row,col of node as well
        // {Node,{row,col}} queue<pair of pair>
        queue<pair<Node*,pair<int,int>>>q;
        //push root in queue
        q.push({root,{0,0}});

        //level order
        while(!q.empty()){
            //using auto to not explicity tell the data struct
            auto front=q.front();
            q.pop();
            Node* &node=front.first;
            auto coordinate=front.second;//coordinate={row,col}
            int &row=coordinate.first;
            int &col=coordinate.second;
            //save in map
            mapping[col][row].insert(node->data);
            //push child  left and right if they exist
            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }
        //map made 
        //now traverse and save it in ans
        for(auto it:mapping){
            auto &innermap=it.second;
            vector<int>vLine;
            for(auto values:innermap){
                //multiset
                auto &mset=values.second;
                //copy whole set into array rather than push back
                vLine.insert(vLine.end(),mset.begin(),mset.end());
            }
            ans.push_back(vLine);
        }
        return ans;
        
    }
int main(){
    Node* root = NULL;

	root = buildTree();

    cout<<"level order traversal of tree"<<endl;
    levelOrderTraversal(root);

    //input->3 9 -1 -1 20 5 -1 -1 7 -1 -1
    //vertical traversal-->9 3 5 20 7
    vector<vector<int>>ans=verticalTraversal(root);

    cout<<"vertical traversal :"<<endl;

    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }



}