#include<iostream>
using namespace std;
//strrchr()->stl function to find the lastr occurence of a char in a string
//method 1->left to right
void lastoccurenceLTR(string s,char x,int i,int& ans){
    //base case
    if(i>=s.length()){
        return;
    }
    if(s[i]==x){
        ans=i;
    }
    //solve one case
    lastoccurenceLTR(s,x,i+1,ans);

}

//method 2-> right to left
void lastoccurenceRTL(string s,char x,int i,int& ans){
    //base case
    if(i<0){
        return;
    }
    if(s[i]==x){
        ans=i;
        return;
    }
    //solve one case
    lastoccurenceRTL(s,x,i-1,ans);

}
int main(){
    string s="abscdscd";
    char x='a';
    int ans=-1;
    //M1
    // int i=0;
    // lastoccurenceLTR(s,x,i,ans);
    // cout<<"the last occurence of char "<<x<<" is at index "<<ans;
    //M2
    int i=s.length()-1;//->starting from last char(right)
    lastoccurenceRTL(s,x,i,ans);
    cout<<"the last occurence of char "<<x<<" is at index "<<ans;
    


}