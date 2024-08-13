#include<iostream>
#include<algorithm>
using namespace std;
bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    
        
    while (i < j) {
        //isalnum check if the s[i] is aplhanumeric or not
        while (!isalnum(s[i]) && i < j) {
            i++;
        }
        while (!isalnum(s[j]) && i < j) {
            j--;
        }
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i++;
        j--;
    }
        
    return true;
}
int main(){
    // Given a string s, return true if it's a palindrome
    // Ex. s = "A man, a plan, a canal: Panama" -> true

    // 2 pointers, outside in, skip non-letters & compare
    string s="A man, a plan, a canal: Panama";
    cout<<isPalindrome(s);
       
}