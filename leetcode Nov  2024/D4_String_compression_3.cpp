#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string compressedString_M2(string word) {
        string comp="";
        char ch=word[0];
        int count=1;

        for(int i=1;i<word.length();i++){
            
            if(ch==word[i] && count<9 ){
                count++;
            }else{
                comp+=to_string(count)+ch;
                //reset for next char
                ch=word[i];
                count=1;
            }
        }
        //append for last char nd count
        comp+=to_string(count)+ch;
        return comp;
        
    }

    string compressedString_M1(string word) {
        string comp = "";

        int n = word.length();
        int i = 0;

        while(i < n) {
            int count = 0;
            char ch   = word[i];

            while(i < n && count < 9 && word[i] == ch) {
                count++;
                i++;
            }

            comp += to_string(count) + ch;
        }

        return comp;
    }
};


int main(){

}