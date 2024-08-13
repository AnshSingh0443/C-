#include<iostream>
using namespace std;
bool isVowel(char ch){
    ch=tolower(ch);
    bool flag;
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
        flag=true;
    }else{
        flag=false;
    }
    return flag;
}
string reverseVowels(string s) {
    int left=0;
    int right=s.length()-1;
    while(left<right){
        if(isVowel(s[left])&&isVowel(s[right])){
            swap(s[left],s[right]);
            left++;
            right--;
        }else if(!isVowel(s[left])){
            left++;
        }else{
            right--;
        }
    }
    return s;
        
}
int main(){
    //PROBLEM STATEMENT
    // Given a string s, reverse only all the vowels in the string and return it.
    // The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

    

    // Example 1:
    // Input: s = "hello"
    // Output: "holle"
    string s="hello";
    cout<<reverseVowels(s);

}