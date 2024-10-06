#include<iostream>
#include<vector>
#include<string>

using namespace std;

    bool areSentencesSimilar(string sentence1, string sentence2) {
        //we need to store each word of sentences
        //this is a lamda functions to store each word split by a space
        auto splitWords = [](const string& sentence){
            vector<string>Words;
            string word="";
            for(char c:sentence){
                if(c==' '){
                    //space
                    if(!word.empty()){
                        //if the word exists
                        Words.push_back(word);
                        //reset
                        word="";
                    }
                }else{
                    word=word+c;
                }
            }
            if(!word.empty()){
                Words.push_back(word);
            }
            return Words;
        };


        //split the sentences into words
        vector<string>words1=splitWords(sentence1);
        vector<string>words2=splitWords(sentence2);

        //ensure that word1 is the lonnger sentence
        if(words1.size() < words2.size() ){
            swap(words1,words2);
        }
        int start=0, end=0;
        int n1=words1.size();
        int n2=words2.size();

        //compare from the start
        while(start<n2 && words1[start]==words2[start]){
            start++;
        }

        //compare from the end
        while(end < n2 && words1[n1-end-1]==words2[n2-end-1]){
            end++;
        }

        //check if the remaining part is in the middle
        if(start+end >= n2){
            return true;
        }
        return false;


    }

int main(){

}