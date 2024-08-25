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
    int maxSum;
    int solve(TreeNode*root){
        if(!root){
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        

        //each node pe ye 3 case calculate hote hai and max sum is updated

        //case 1-> left and right both are good so path ios like a arch->we will not return this up->violates path
        int niche_ka_ans=left+right+root->val;

        //case 2->only left ya right is good->select maximm->is case me return kar sakte hai as we choose either left or right ->liner path
        int only_ek_acha=max(left,right)+root->val;

        //case 3->both left and right are not good->dono -ve hai->return root->val->>is case me bhi upar return kar sakte hai as only one node is selected
        int only_root=root->val;
        //update maxsum
        maxSum=max(maxSum,max(niche_ka_ans,max(only_ek_acha,only_root)));

        return max(only_ek_acha,only_root);//we return case 2 and 3 only

    


    }
    int solve2(TreeNode*root){
        if(!root){
            return 0;
        }
        //my max with 0 -->to handle -ve nodes we do not want to include them->so 0 is returned 
        int left=max(solve2(root->left),0);
        int right=max(solve2(root->right),0);

        //curr sum->root->val + max from right + max from left
        int currPath=root->val+left+right;
        //update maxSum 
        maxSum=max(maxSum,currPath);

        //why? this since we want to return a liner path to the upper root node we select the curr node + max from left or right->why not return currpath->beacuse it takes sum from both left and right we cannot send a path that is arch and linear
        return root->val + max(left,right);

    }
   
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve2(root);
        return maxSum;
    }

int main(){

}