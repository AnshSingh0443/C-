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

     //fast way->O(n)
    bool isbalanced=true;
    int height(TreeNode*root){
        if(!root){
            return 0;
        } 

        int lh=height(root->left);
        int rh=height(root->right);

        //check balanced
        if(isbalanced && abs(lh-rh) > 1){
            isbalanced=false;
        }

        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        //har node pr height check karte tym hi check kar lo blaanced he ki nahi
        height(root);
        return isbalanced;
        
    }

int main(){

}