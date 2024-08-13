#include<iostream>
#include<string>
#include<vector>
using namespace std;
class TrieNode{
        public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        //we neeed child count
        int childCount;

        TrieNode(char d) {
                this->data = d;
                for(int i=0; i<26 ; i++) {
                        children[i] = NULL;
                }
                
                this->isTerminal = false;
                childCount=0;
        }
};

void insertWord(TrieNode* root, string word) {
        //cout << "Inserting " << word << endl;
   //base case
        if(word.length() == 0) {
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->children[index] = child;
                //increment
                root->childCount++;
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}
    void findLCP(TrieNode*root,string word,string &ans){
        //base case
        if(root->isTerminal){
            return;
        }
        for(int i=0;i<word.length();i++){
            char ch=word[i];

            if(root->childCount==1){
                ans.push_back(ch);
                //then move to child
                int index=ch-'a';
                root=root->children[index];
            }
            else{
                //stop if childcount is  more than one
                break;
            }

            //stop when terminal is reached
            if(root->isTerminal){
                break;
            }
            
        }
    }
    

    string longestCommonPrefix(vector<string>& strs) {
        //BRUTE FORCE
        // int i=0;
        // string ans;
        
        // while(true){
        //     char curr_ch=0;
        //     for(auto str:strs){
        //         //for each string in strs
        //         if(i>=str.length()){
        //             //out of bound
        //             curr_ch=0;
        //             break;
        //         }
        //         //first one
        //         if(curr_ch==0){
        //             curr_ch=str[i];//curr_ch=f
        //         }
        //         else if(curr_ch!=str[i]){
        //             curr_ch=0;
        //             break;
        //         }

        //     }
        //     if(curr_ch==0){
        //         break;
        //     }
        //     ans.push_back(curr_ch);
        //     i++;
        // }
        // return ans;

        //USING Trie Node
        
        //1.push all words into trienode
        //create root first
        TrieNode* root=new TrieNode('-');

        for(auto str:strs){
            insertWord(root,str);
        }
        //2.find LCP using the first string(can be any)

        string first=strs[0];
        string ans="";

        findLCP(root,first,ans);

        return ans;
            
    }

int main(){
    vector<string> strs={"flower","flow","flight"};
    //longest common prefix=fl

    cout<<longestCommonPrefix(strs);



}