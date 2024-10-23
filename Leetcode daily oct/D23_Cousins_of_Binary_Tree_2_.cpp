#include<iostream>
#include<vector>
#include<queue>

using namespace std;

  
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 


    TreeNode* replaceValueInTree_Brute(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        //step 1 find the level sum for each level in tree
        vector<int>levelSum;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int currlevelsum=0;
            int n=q.size();
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                currlevelsum +=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            //level end
            levelSum.push_back(currlevelsum);
        }

        //step 2 update each node as data=level sum - sibling sum
        //use bfs again
        q.push(root);
        root->val=0;//root has no cousins
        int i=1;//index to know the level start form 1 becuz root has no cuusins 

        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* currNode=q.front();
                q.pop();
                //sbiling sum
                int siblingSum=0;
                siblingSum += currNode->left!=NULL? currNode->left->val : 0;
                siblingSum += currNode->right!=NULL? currNode->right->val : 0;
                //level sum
                if(currNode->left){
                    currNode->left->val=levelSum[i]-siblingSum;
                    q.push(currNode->left);
                }
                if(currNode->right){
                    currNode->right->val=levelSum[i]-siblingSum;
                    q.push(currNode->right);
                }
                
            }
            i++;// curr level ends->increse level
        }

        return root;



        
    }

    //Approach-2 (1 Pass)
    //T.C : O(n)
    //S.C : O(n)
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }        

        queue<TreeNode*> que;
        que.push(root);
        int levelSum = root->val;

        while(!que.empty()) {
            int n = que.size();
            int nextLevelSum = 0;

            while(n--) {
                TreeNode* curr = que.front();
                que.pop();

                curr->val = levelSum - curr->val;

                int siblingSum = (curr->left != NULL ? curr->left->val : 0);
                siblingSum += (curr->right != NULL ? curr->right->val : 0);

                if(curr->left) {
                    nextLevelSum += curr->left->val;
                    curr->left->val = siblingSum;
                    que.push(curr->left);
                }


                if(curr->right) {
                    nextLevelSum += curr->right->val;
                    curr->right->val = siblingSum;
                    que.push(curr->right);
                }
            }

            levelSum = nextLevelSum;
        }

        return root;
    }

int main(){

}