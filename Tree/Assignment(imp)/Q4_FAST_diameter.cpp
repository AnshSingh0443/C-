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

    int diameter=0;
    int height(TreeNode*root){
        if(!root){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        //curr diamanter=left height+rightheight
        int Currdiameter=left+right;
        //update diameter if curr is greater
        diameter=max(diameter,Currdiameter);
        //height at curr node ->max(left height, rightheight)+1
        return max(left,right)+1;
    }
    //O(N)
    int diameterOfBinaryTree(TreeNode* root) {
        //fast way
        //keep track of height on the way to find diameter
        height(root);
        return diameter;
    }


int main(){
    return 0;
}