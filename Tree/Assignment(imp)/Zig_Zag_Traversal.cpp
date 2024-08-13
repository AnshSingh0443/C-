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
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>>traversal;
        queue<Node*>q;
        //base case
        if(root==NULL){
            return traversal;
        }
        q.push(root);
        bool LeftToRight=true;//initally true as lvl 0->even


        while(!q.empty()){
            int width=q.size();//no of nodes in a level is equal to the size to queue
            vector<int>Onelevel(width);
            for(int i=0;i<Onelevel.size();i++){
                Node*front=q.front();
                q.pop();
                //use index to fill acc to bool valve of left to right
                int index= LeftToRight? i :width-i-1;//why width-i-1 will always fill array from the back ie right to left
                Onelevel[index]=front->data;
                //push children
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }

            }
            //change direction
            LeftToRight=!LeftToRight;
            //push onw level onto ans
            traversal.push_back(Onelevel);

        }  
        return traversal;      
        
    }
int main(){
    Node* root = NULL;

	root = buildTree();

    cout<<"level order traversal of tree"<<endl;
    levelOrderTraversal(root);

    cout<<"zig zag level traversal of tree"<<endl;
    vector<vector<int>>res=zigzagLevelOrder(root);

    for(auto level:res){
        for(int i=0;i<level.size();i++){
            cout<<level[i]<<" ";
        }
        cout<<endl;
    }

}