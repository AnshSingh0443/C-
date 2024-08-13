#include<iostream>
using namespace std;
bool palindromecheck(string s,int start,int end){
    //base case
    if(start>=end){
        return true;
    }
    //solve one case
    return s[start]==s[end]?palindromecheck(s,start+1,end-1):false;
}
int main(){
    cout<<palindromecheck("anna",0,3);

}