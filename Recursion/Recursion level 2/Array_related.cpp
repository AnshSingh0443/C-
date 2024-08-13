#include<iostream>
using namespace std;
//1.Print array recursively
void print(int arr[], int n, int i) {
        //base case
        if( i >= n) {
            return;
        }

        //1 case solve krdia
        cout << arr[i] << "->";
        //baaki recursion sambhal lega
        print(arr, n, i+1);

}
//2.max in array
void findMax(int arr[], int n, int i, int& maxi) {
        //base case
        if(i >= n) {
                //array agar khtam hogya, poora traverse hogya
                //toh wapas aajao
                return;
        }

        //1 case solve krna h 
        //current element ko cjheck karo for max
        if(arr[i] > maxi) {
                maxi = arr[i];
        }

        //baaki recursion sambhal lega
        findMax(arr, n, i+1, maxi);
}

//3.Min in array
void findMin(int arr[], int n, int i, int& mini ){
        //base case
        if( i >= n) {
                return;
        }


        //1 case solve krna padega
        mini = min(mini, arr[i]);


        //baaki recursion sambhal lega
        findMin(arr, n, i+1, mini);

}
int main(){
    int arr[]={1,2,3,4};
    print(arr,4,0);
    cout<<endl;

    int mini=INT_MAX;
    findMin(arr,4,0,mini);
    cout<<mini<<endl;

    int maxi=INT_MIN;
    findMax(arr,4,0,maxi);
    cout<<maxi;




}