#include <iostream>
using namespace std;
void printPermutation(string &str, int i) {
  //base case
  if(i >= str.length()) {
    cout << str << " ";
    return;
  }

//swapping
  for(int j=i; j<str.length(); j++) {
    //swap
    swap(str[i], str[j]);
    //rec call
    printPermutation(str, i+1);

    //backtracking - to recreate the original input string
    //while returing we swap again to undo the change done to the original string 
    swap(str[i], str[j]);
  }

}
int main() {
  string str = "pqrs";
  int i = 0;
  printPermutation(str,i);
  return 0;
}