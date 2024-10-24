#include<iostream>

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

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        //flip quilvalent if tree 1 is equal to tree 2 after some num flip operations on tree 1
        //base cases if either is  null and other is not
        if(!root1 && root2){
            return false;
        }
        if(!root2 && root1){
            return false;
        }
        //both are null thus  the same
        if(!root1 && !root2){
            return true;
        }
        if(root1->val !=root2->val){
            return false;
        }
        //rec
        //no swap value should be same
        bool noswap=flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
        //opp value should be same
        bool swap=flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);

        return noswap || swap;
    }
};

int main(){

}