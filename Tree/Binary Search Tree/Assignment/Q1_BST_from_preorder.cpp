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
 
class Solution {
public:
    TreeNode * build(int &i,int min,int max,vector<int>& preorder){
        //base case
        if(i>=preorder.size()){
            return nullptr;
        }
        TreeNode *root=nullptr;
        if(preorder[i]>min && preorder[i]<max){
            //in range
            //root left  right
            root=new TreeNode(preorder[i]);
            i++;
            //call for left -> max will be root->val as in bst left me root se chote hi jayge
            root->left=build(i,min,root->val,preorder);

            //call for right -> min will be root->val as in bst right me root se bade hi jayge
            root->right=build(i,root->val,max,preorder);
            
        }
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //using recursion to build the tree
        int min=INT_MIN;
        int max=INT_MAX;
        int i=0;

        return build(i,min,max,preorder);

    }
};

int main(){

}