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
void printlist(Node * head){
    while(head){
        cout<<head->data<<" ";
        head=head->right; 
    }
}
void flatten(Node* root) {
        Node*CurrNode=root;
        //find predecessor of the current node
        while(CurrNode){
            if(CurrNode->left){
                //pred= 1st left se right until right null
                Node*pred=CurrNode->left;
                while(pred->right){
                    pred=pred->right;
                }
                //pred ka right curr k right pe set karo
                pred->right=CurrNode->right;
                //current node ka right ko left pe set karo
                CurrNode->right=CurrNode->left;
                //left ko NULL karo
                CurrNode->left=nullptr;
            }
            //do the same for next node until not null
            CurrNode=CurrNode->right;


        }
        
}
int main(){
    Node* root = NULL;

	root = buildTree();

    cout<<"level order traversal of tree"<<endl;
    levelOrderTraversal(root);
    int targetSum=8;
    //input tree:1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
    //pre oredr of this tree:1 2 3 4 5 6
    //output->linked list:1->2->3->4->5->6
    cout<<"linked list:";
    flatten(root);
    printlist(root);


}