#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> factorial(int n){
    vector<int>ans;
    ans.push_back(1);
    int carry=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<ans.size();j++){
            int x=(ans[j]*i)+carry;
            ans[j]=x%10;
            carry=x/10;
        }
        if(carry){
            ans.push_back(carry);
        }
    }
    reverse(ans.begin(),ans.end());
    for(int elem:ans){
        cout<<" "<<elem;
    }
    return ans;

}
int main(){
    //factorial of large nums cannot be stored in int so we use arrays(dynamic)->vector
    factorial(7);

}