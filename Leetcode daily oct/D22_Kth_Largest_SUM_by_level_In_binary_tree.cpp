#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>
#include<algorithm>

using namespace std;



//  * Definition for a binary tree node.
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
    // Function to do level order traversal and 
// return a 2D vector
vector<vector<long long>> levelOrder(TreeNode *root) {
    
  
    vector<vector<long long>> result;
    if (root == nullptr) return result;

    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    vector<long long> currentLevel;

    while (q.size() > 1) {
        TreeNode *curr = q.front();
        q.pop();

        // Condition to check occurrence of next level.
        if (curr == nullptr) {
            result.push_back(currentLevel); 
            currentLevel.clear();           
            q.push(nullptr);                   
        } 
        else {
            currentLevel.push_back(curr->val);  

            if (curr->left) q.push(curr->left);  
            if (curr->right) q.push(curr->right); 
        }
    }

    if (!currentLevel.empty()) {
        result.push_back(currentLevel); 
    }

    return result;
}
    long long kthLargestLevelSum_Brute(TreeNode* root, int k) {
        //steps 
        //1 find the level order traversal
        //2 acc to that level find the corresponding sum
        //3 save these sum acc to there level and return the sum for k
        //using long long type data and not int due to constraint uses
        vector<long long>levelsums;
        vector<vector<long long>> traversal = levelOrder(root);
         priority_queue<long long>pq;
        for (const auto &level : traversal) {
            long long sum=0;
            for (int val : level) {
               sum=sum+val;
            }
            cout<<sum<<" ";
            levelsums.push_back(sum);
            pq.push(sum);
           
        }
        if(k>levelsums.size()){
            return -1;
        }
        sort(levelsums.begin(),levelsums.end(),greater<long long>());
        
        return levelsums[k-1];
       
       

        
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> res;      // To store sum of each level
        queue<TreeNode*> q;         // Queue for level-order traversal (BFS)
        
        q.push(root);               // Start BFS from the root node
        while (!q.empty()) {
            int n = q.size();       // Number of nodes at the current level
            long long sum = 0;      // Sum of node values at the current level
            
            // Process all nodes at the current level
            while (n--) {
                TreeNode* node = q.front(); q.pop();   // Get the front node from the queue
                sum += (long long)node->val;           // Add node's value to the level sum
                
                // Push left and right children of the node to the queue (if they exist)
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(sum);     // Store the sum of the current level
        }

        // If k is greater than the number of levels, return -1
        if (k > res.size()) return -1;
        
        // Sort the level sums in descending order
        sort(res.begin(), res.end(), greater<long long>());
        
        // Return the k-th largest level sum (k-1 due to 0-based indexing)
        return res[k-1];
    }
};


int main(){

}