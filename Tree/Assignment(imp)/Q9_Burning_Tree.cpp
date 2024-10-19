#include<iostream>
#include<vector>
#include<unordered_map>
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
 
    TreeNode*FindTargetAndMakeMapping( TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parentMap,int target){
        //using any traversl ->level order travesal
        TreeNode*targetNode=NULL;
        queue<TreeNode*>q;
        q.push(root);
        parentMap[root]=0;

        while(!q.empty()){
            TreeNode*front=q.front();
            q.pop();
            //check if target
            if(front->val==target){
                targetNode=front;
            }

            if(front->left){
                q.push(front->left);
                //mark parent mapping
                parentMap[front->left]=front;
            }
            if(front->right){
                q.push(front->right);
                parentMap[front->right]=front;
            }

        }
        return targetNode;

    }

    int InfectTree(TreeNode*targetNode,unordered_map<TreeNode*,TreeNode*>&parentMap){
        //using visited->map to mark if the node is already infected/burned
        //using queue to push adjacent nodes to burn and also increase time by one at the same time
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        int t=0;
        q.push(targetNode);
        visited[targetNode]=true;
        while(!q.empty()){
            int size=q.size();
            bool isFireSpread=false;
            //all nodes are burnt/infected simultanesously
            for(int i=0;i<size;i++){
                //burn / infect each node
                TreeNode*front=q.front();
                q.pop();
                //burn left
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                    isFireSpread=true;
                }
                //burn right
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                    isFireSpread=true;
                }
                //burn parent
                if(parentMap[front] && !visited[parentMap[front]]){
                    q.push(parentMap[front]);
                    visited[parentMap[front]]=true;
                    isFireSpread=true;
                }

               

            }
            if(isFireSpread){
                t++;
            }
        }
        return t;

    }
    int amountOfTime(TreeNode* root, int start) {
        //1. find target node

        //2. make a mapping of node to its parent->why?->as infection spreads to parent also we need to access it using this map
        unordered_map<TreeNode*,TreeNode*>parentMap;
        TreeNode*targetNode=FindTargetAndMakeMapping(root,parentMap,start);

        //3.adjacent node ka matlab or can be->parent,rightchild and leftchild
        return InfectTree(targetNode,parentMap);

        
    }


int main(){

}