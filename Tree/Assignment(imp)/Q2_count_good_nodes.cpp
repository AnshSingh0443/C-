#include<iostream>
#include<vector>

using namespace std;
 struct TreeNode {
     int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
    void solve(TreeNode*root,int &result,int maxsofar){
        if(!root){
            return;
        }
        //compare max with curr node
        if(root->val >= maxsofar){
            //valid-good node
            result+=1;
            //update max
            maxsofar=max(maxsofar,root->val);
        }
        solve(root->left,result,maxsofar);
        solve(root->right,result,maxsofar);

    }
    int result=0;
    int goodNodes(TreeNode* root) {
        //not good node->agar root se le kar curr node k path me koi asa node hai hai jiske value is greater than curr node ki value
        //root->always good node->maxsofar=root->val

        //we need a max that saves the maximum seen till current in order to compare it with current node->to find out if it is good or not

        solve(root,result,root->val);
        return result;

        
    }

int main(){

}