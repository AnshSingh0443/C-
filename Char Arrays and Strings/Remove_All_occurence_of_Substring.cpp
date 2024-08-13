#include<iostream>
using namespace std;
string removeOccurrences(string s,string part){
    int pos=s.find(part);//->will give a valid index or npos(not valid)
    // jab tak pos unvlaid nahi hota->until there are no part left in the string
    while(pos!=string::npos){
        s.erase(pos,part.length());//starting index and length of substring part
        pos=s.find(part);
    }
    return s;
}

int main(){
    //EXAMPLE:->
    // Input: s =daabcbaabcbc , part = "abc"
    // Output: "dab"
    // Explanation: The following operations are done:
    // - s = daabcbaabcbc, remove "abc" starting at index 2, so s = "dabaabcbc".
    // - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
    // - s = "dababc", remove "abc" starting at index 3, so s = "dab".
    // Now s has no occurrences of "abc".
    string s="daabcbaabcbc";
    string part="abc";
    string res=removeOccurrences(s,part);
    cout<<res;

    // to find substring in string->find
    // to remove substring in string->erase
}