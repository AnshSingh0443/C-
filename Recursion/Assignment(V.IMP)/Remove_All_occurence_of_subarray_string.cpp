#include<iostream>
using namespace std;
    void removeOCCre(string& s,string& part){
        int found=s.find(part);
        if(found!=string::npos){
            //left part 
            string left_part=s.substr(0,found);
            //right part
            string right_part=s.substr(found+part.size(),s.length());

            s=left_part+right_part;//concatenate the string left and right bascially removing part string from the original one

            removeOCCre(s,part);
            
        }else{
            //base case
            return;
        }
    }
    string removeOccurrences(string s,string part){
        removeOCCre(s,part);
        return s;
    }

int main(){
    string s= "daabcbaabcbc";
    string part="abc";
    cout<<removeOccurrences(s,part);

}