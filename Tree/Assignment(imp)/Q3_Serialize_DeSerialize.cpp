#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<bits/stdc++.h>

using namespace std;
 struct TreeNode {
     int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //convert to  string
        //base case
        if(root==NULL){
            return "";
        }
        string s="";

        //apply levelorder traversal
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* currNode=q.front();
            q.pop();
            if(currNode==NULL){
                //#->is used to denote null
                s.append("#,");
            }else{
                s.append(to_string(currNode->val)+",");
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        cout<<s<<endl;
        return s;   
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //string back to bt
        //base case
        if(data.size()==0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');//get first sperarated by ,
        //create node
        TreeNode*root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*currNode=q.front();
            q.pop();
            //attach left 
            getline(s,str,',');
            if(str=="#"){
                //null
                currNode->left=NULL;
                cout<<"left:"<<str<<endl;
            }else{
                TreeNode *leftNode=new TreeNode(stoi(str));
                cout<<"left:"<<leftNode->val<<endl;
                currNode->left=leftNode;
                q.push(leftNode);
            }
            //attach right
            getline(s,str,',');
            if(str=="#"){
                //null
                currNode->right=NULL;
                cout<<"right:"<<str<<endl;
            }else{
                TreeNode *rightNode=new TreeNode(stoi(str));
                cout<<"right:"<<rightNode->val<<endl;
                currNode->right=rightNode;
                q.push(rightNode);

            }
        }
        return root;
        
    }

int main(){
    return 0;
}