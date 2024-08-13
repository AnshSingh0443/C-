#include<iostream>
#include<vector>
using namespace std;
int  main(){
    //set ->data structure use to store unique values only
    // set<int>st;
    //3 sorted array find common element
    vector<int>arr1{1,5,10,20,40,80};
    vector<int>arr2{6,7,20,80,100};
    vector<int>arr3{3,4,15,20,30,60,80,100};
    //array to store common element and should not have any duplicates
    vector<int>ans;// use set instead
    int i,j,k=0;
    while(i<arr1.size() && j<arr2.size() &&k <arr3.size()){
        if(arr1[i]==arr2[j] &&arr2[j]==arr3[k]){
            ans.push_back(arr1[i]);
            // st.insert(arr1[i]); will only insert if the value is unique so no duplicates are inserted
            i++;
            j++;
            k++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr3[k]){
            j++;
        }
        else{
            k++;
        }

    }
    // to iterate a set
    // for(auto i:st){
    //     //do something
    // }
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}