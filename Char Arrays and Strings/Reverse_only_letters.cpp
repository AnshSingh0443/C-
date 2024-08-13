#include<iostream>
#include<algorithm>
using namespace std;
//2 Pointer approach-do not swap when when we incur a non english letter
//isalpha()-check if a char is aplhabet or not
string reverseOnlyLetters(string s) {
    int left=0;
    int right=s.length()-1;
    while(left<right){
        if(isalpha(s[left])&& isalpha(s[right])){
            swap(s[left],s[right]);
            left++;
            right--;
        }else if(!isalpha(s[left])){
            left++;
        }else{
            right--;
        }
    }
    return s;
}
int main(){
    //PROBLEM STATEMENT
        // Given a string s, reverse the string according to the following rules:
        // All the characters that are not English letters remain in the same position.
        // All the English letters (lowercase or uppercase) should be reversed.
        // Return s after reversing it.

    //Example
    // Input: s = "Test1ng-Leet=code-Q!"
    // Output: "Qedo1ct-eeLg=ntse-T!"   
    string s="Test1ng-Leet=code-Q!";
    cout<<reverseOnlyLetters(s);
}