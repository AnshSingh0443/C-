#include<iostream>
#include<vector>

using namespace std;


//  Definition for a binary tree node.
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
    int level[1000001]; //level of each node
    int height[100001]; //height of each node
    int levelMaxHt[100001];// maximum height at each level
    int levelSecondMaxHt[100001];//2nd max height at each level 
    //why 2nd max becuz if node getting deleted has the max height at that level thus we would need the 2nd max height at that level

    int findHeight(TreeNode* root, int l) {
        if(!root) {
            return 0;
        }
        //fill node at level
        level[root->val] = l;
        //find height for that node and save
        height[root->val] = max(findHeight(root->left, l+1), findHeight(root->right, l+1)) + 1;

        //update the mat height at that level
        if(levelMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = levelMaxHt[l];
            levelMaxHt[l] = height[root->val];
        }
        //update 2nd max height 
        else if(levelSecondMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = height[root->val];
        }

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        //precompute and fill the aarrays->levels,heights,maxheighttatlevel,2ndmaxheigth at level
        findHeight(root, 0);

        vector<int> result;
        //logic->if a node is deleted check other nodes in the  same level and find the maximum height ->H

        for(int &node : queries) {
            //node = that we have to delete
            int L = level[node]; //O(1) //node ka level hai ye

            //L + H - 1
            //levelMaxHt[L] == height[node]  means the node geeting deleted has the max ht at that lvel->choose 2nd max height
            int tempResult = L + (levelMaxHt[L] == height[node] ? levelSecondMaxHt[L] : levelMaxHt[L]) - 1;

            result.push_back(tempResult);
        } 

        return result;
    }
};

int main(){

}