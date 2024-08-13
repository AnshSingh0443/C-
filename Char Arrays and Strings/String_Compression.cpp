#include<iostream>
#include<vector>
using namespace std;
int compress(vector<char>& s) {
    int index=0;
    char prev=s[0];
    int count=1;
    for(int i=0;i<s.size();i++){
        if(s[i]==prev){
            count++;
        }else{
            s[index]=prev;
            index++;
            if(count>1){
                int start=index;
                while(count){
                    s[index]=(count%10)+'0';
                    index++;
                    count=count/10;
                }
                reverse(s.begin()+start,s.end()+index);
            }
            //reset
            prev=s[i];
            count=1;
        }
    }
    s[index]=prev;
    if(count>1){
        int start=index;
        while(count){
            s[index]=(count%10)+'0';
            index++;
            count=count/10;
        }
        reverse(s.begin()+start,s.end()+index);
    }
  
    return index;
        
}
int main(){
    //Example
    // Input: chars = ["a","a","b","b","c","c","c"]
    // Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
    // Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
    vector<char>s{'a','a','b','b','c','c','c'};
    cout<<compress(s);

}