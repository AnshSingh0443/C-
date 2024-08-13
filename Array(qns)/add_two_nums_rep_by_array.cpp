#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    vector<int>arr1{1,2,0};
    vector<int>arr2{5,0};
    string ans;
    int i=arr1.size()-1;
    int j=arr2.size()-1;
    int carry=0;
    //when both nums have same no of digits
    while(i>=0&&j>=0){
        int x=arr1[i]+arr2[j]+carry;
        int digit=x%10;
        ans.push_back(digit + '0');//to store in string
        carry=x/10;
        i--;
        j--;
    }
    //when arr1 has more digits than arr2
    while(i>=0){
        int x=arr1[i]+0+carry;
        int digit=x%10;
        ans.push_back(digit + '0');//to store in string
        carry=x/10;
        i--;
    }
    //when arr2 has more digits than arr1
    while(j>=0){
        int x=0+arr2[j]+carry;
        int digit=x%10;
        ans.push_back(digit + '0');//to store in string
        carry=x/10;
        j--;
    }
    //if any carry is left
    if(carry){
        ans.push_back(carry+'0');
    }
    //remove extras 0s
    while(ans[ans.size()-1]==0){
        ans.pop_back();
    }
    //ans is reverse of string
    reverse(ans.begin(),ans.end());
    cout<<ans;

}