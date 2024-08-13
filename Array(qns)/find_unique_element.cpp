#include<iostream>
#include<vector>
using namespace std;
int unique_element(vector<int>arr){
    int ans=0;//xor any num  with 0 is the number itself thats why
    for(int i=0;i<arr.size();i++){
        //xor all elements with ans
        ans=ans^arr[i];//XOR operation same ,same-0 amd diff,diff-1 so duplicated elements will all cancel out and unique element is stored un ans
    }
    return ans;
}
int main(){
    //given that only 1 elemnnts is not repeated
    int n;
    cout<<"enter the size of array:";
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cout<<"enter element "<<i;
        cin>>arr[i];
    }
    cout<<"the unique element is :"<<unique_element(arr);



}