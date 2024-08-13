#include<iostream>
using namespace std;
void ReverseString(string& s,int start,int end){
    //base case
    if(start>=end){
        return;
    }
    //solve one case
    swap(s[start],s[end]);

    //RR
    ReverseString(s,start+1,end-1);
}
int main(){
    string s="ansh";
    int start=0;
    int end=s.length()-1;
    ReverseString(s,start,end);
    cout<<s;
    

}