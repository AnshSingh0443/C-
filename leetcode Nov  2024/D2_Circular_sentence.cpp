#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool isCircularSentence_1(string sentence) {
        //step 1 take words in the sentence and store it
        vector<string>words;
        string word;
        //dont know why in vscode gave error woked in leetcode 
        // stringstream s(sentence);
        // while(s >> word){
        //     words.push_back(word);
        // }
        int n=words.size();


        //start comparing from last and first word

        char last=words[n-1].back();//last char of word-> to be ciruclar should be equal to  the first char of the first word
    
        for(int i=0;i<n;i++){
            if(words[i].front() != last){
                return false;
            }
            last=words[i].back();
        }

        return true;

        
    }
    bool isCircularSentence(string sentence) {
        //iterate over sentence if it is a space check i-1 and 1+1 chars ->should be same
        //additionally to be cirucalr check first char and last char
       

        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' ' && sentence[i-1] != sentence[i+1]){
                return false;
            }
        }
        if(sentence[0]==sentence[sentence.size()-1]){
            return true;
        }else{
            return false;
        }

        return true;


        
    }
};

int main(){

}