#include<iostream>
#include<vector>

using namespace std;
class WordDictionary {
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
    WordDictionary() {
         root=getNode();

        
    }
    
    void addWord(string word) {
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
    bool searchUtil(string word,trieNode *root){
        trieNode *curr = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            char ch = word[i];
            
            if(ch == '.') {
                
                for(int j = 0; j<26; j++) {
                    if(curr->Children[j] != NULL)
                        if(searchUtil(word.substr(i+1),curr->Children[j]))
                            return true;
                }
                
                return false;
                
            } else if (curr->Children[ch-'a'] == NULL) {
                return false;
            }
            
            curr = curr->Children[ch-'a']; 
        }
        return (curr != NULL && curr->isEndOfWord); 
        

    }
    bool search(string word) {
        return searchUtil(word,root);  
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


int main(){
    return 0;
}