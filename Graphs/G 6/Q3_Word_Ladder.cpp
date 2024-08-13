#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //bfs logic
        queue<pair<string,int>>q;//queue store a pair of {word,count} 
        //here count is the no if strings encounterd/transformed till now which are present  in the wordlist 

        unordered_set<string>st(wordList.begin(),wordList.end());

        //initial push
        q.push({beginWord,1});
        //remove form list->to avoid it encountering it again while transforming
        st.erase(beginWord);

        while(!q.empty()){
            pair<string,int>fnode=q.front();
            q.pop();
            string currWord=fnode.first;
            int currCount=fnode.second;

            //check if the front node word is our destination/endword
            if(currWord==endWord){
                return currCount;
            }

            //replace each char of the currword and chechk in wordlist
            for(int index=0;index<currWord.length();index++){
                //save original char -->hit->ait to zit
                //next i ko replace karna hai from hit but wwe have zit thus 
                char originalchar=currWord[index];
                
                for(char ch='a';ch <= 'z';ch++){
                    currWord[index]=ch;
                    //check if present in wordlist
                    if(st.find(currWord)!=st.end()){
                        //present
                        //push to queue and erases form the wordlist so we dont encounter it again
                        q.push({currWord,currCount+1});
                        st.erase(currWord);
                    }
                }
                //back to original
                //zit-->hit
                //hzt--->hot
                currWord[index]=originalchar;
            }

        }

        return 0;
        
    }

int main(){
    // A transformation sequence from word beginWord to word endWord 
    // using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    // Every adjacent pair of words differs by a single letter.
    // Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    // sk == endWord
    // Given two words, beginWord and endWord, 
    // and a dictionary wordList, 
    // return the number of words in the shortest transformation sequence from beginWord to endWord,
    //  or 0 if no such sequence exists.

    // Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    // Output: 5
    // Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long

    string beginWord="hit";
    string endWord="cog";
    vector<string>wordList={"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength(beginWord,endWord,wordList);

}