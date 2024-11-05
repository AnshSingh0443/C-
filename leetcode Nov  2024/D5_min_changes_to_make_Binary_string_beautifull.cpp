#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int minChanges_1(string s) {
        int n=s.length();

        int count=0;
        char ch=s[0];
        int changes=0;

        for(int i=0;i<n;i++){
            if(s[i]==ch){
                //if curr char is same as prev increase count and continue
                count++;
                continue;
            }
            //not equal->check if prev count was even->to make partition
            if(count%2==0){
                //reset count
                count=1;//starting new substring 
            }
            else{
                // a change is need to be made ->to make string even len
                changes+=1;
                //reset count
                count=0;
            }
            //update char
            ch=s[i];
        }

        return changes;
    }
    //optimized
    int minChanges(string s) {
        int n=s.length();

        int changes=0;

        //check in pair of two(even)->if s[i] and s[i+1] are eqaul then no changes is to be made ->i=i+2

        for(int i=0;i<n;i=i+2){
            if(s[i]!=s[i+1]){
                changes+=1;
            }
        }
        return changes;
    }
};


int main(){

}