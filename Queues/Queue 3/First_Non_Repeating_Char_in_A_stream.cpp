#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    string s="aabc";
    int frequency[26]={0};
    queue<char>q;

    string ans="";

    //L--->R
    for(int i=0;i<s.length();i++){
        //curren char
        char ch=s[i];

        //increment freq
        frequency[ch-'a']++;

        //push onto queue
        q.push(ch);

        while(!q.empty()){
            //freq of the char in front of queue > 1->pop
            if(frequency[q.front()-'a']>1){
                q.pop();
            }else{
                //freq==1
                //store in ans
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
        
    }
    cout<<ans;
}