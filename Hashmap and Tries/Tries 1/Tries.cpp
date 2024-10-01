#include <iostream>
using namespace std;

//letcode implentation

class Trie {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode* Children[26];
    };
    //fxn to create new node
    trieNode* getNode(){
        trieNode* newNode =new trieNode();
        newNode->isEndOfWord=false;
        for(int i=0;i<26;i++){
            
            newNode->Children[i]=NULL;
        }
        return newNode;
    }
    trieNode* root;
    Trie() {
      root=getNode();
    }
    
    void insert(string word) {//apple
        //we need a pointer to traverse while creating node acc to word
        trieNode* curr=root;
        for(int i=0;i<word.length();i++){
            //check if it is present or not

            char ch=word[i];
            int index=ch-'a';
            if(curr->Children[index]==NULL){
                //not present->create the node
                curr->Children[index]=getNode();
                
            }
            curr=curr->Children[index];
        }
        //last ch-e
        curr->isEndOfWord=true;
        
    }
    
    bool search(string word) {
        //we need a pointer to traverse while creating node acc to word
        trieNode* curr=root;
        for(int i=0;i<word.length();i++){
            //check if it is present or not

            char ch=word[i];
            int index=ch-'a';
            if(curr->Children[index]==NULL){
                //not prsent
                return false;
            }
            curr=curr->Children[index];
        }
        //last ch-e
        if(curr!=NULL && curr->isEndOfWord==true){
            return true;
        }
        else    
            return false;
        
    }
    
    bool startsWith(string prefix) {
        //we need a pointer to traverse while creating node acc to word
        trieNode* curr=root;
        int i=0;
        for(i=0;i<prefix.length();i++){
            //check if it is present or not

            char ch=prefix[i];
            int index=ch-'a';
            if(curr->Children[index]==NULL){
                //not prsent
                return false;
            }
            curr=curr->Children[index];
        }
        if(i==prefix.length()){
            return true;
        }
        return false;
        
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


class TrieNode{
        public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char d) {
                this->data = d;
                for(int i=0; i<26 ; i++) {
                        children[i] = NULL;
                }
                this->isTerminal = false;
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
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
                return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else{
                return false;
        }
        //rec call
        return searchWord(child, word.substr(1));

}

int main() {
  TrieNode* root = new TrieNode('-');

  //root->insertWord("coding");
  insertWord(root, "coding");
  insertWord(root, "code");
  insertWord(root, "coder");
  insertWord(root, "codehelp");
  insertWord(root, "baba");
  insertWord(root, "baby");
  insertWord(root, "babu");
  insertWord(root, "shona");
  cout << "Searching " << endl;
  if(searchWord(root,"cod")) {
          cout << "present" << endl;
  }
  else {
          cout << "absent" << endl;
  }

  return 0;
}

