#include<iostream>
#include<vector>
using namespace std;
int main(){
    // 0-red,1-white,2-blue
    vector<int>arr{2,0,1};
    //1ST WAY
    // sort(arr.begin(),arr.end()); will sort the whole array (0,1,2)



    // //2nd way-overwrite with count  of 0,1,2
    // int countzero=0,countone=0,counttwo=0;

    // for(int i=0;i<arr.size();i++){
    //     if(arr[i]==0){
    //         countzero++;
    //     }
    //     if(arr[i]==1){
    //         countone++;
    //     }
    //     if(arr[i]==2){
    //         counttwo++;
    //     }
    // }
    // cout<<"count of 0 is:"<<countzero<<endl;
    // cout<<"count of 1 is:"<<countone<<endl;
    // cout<<"count of 2 is:"<<counttwo<<endl;
    // //overwite the array
    // int i=0;
    // while(countzero>0){
        
    //     arr[i]=0;
    //     i++;
    //     countzero--;
    // }
    // while(countone>0){
        
    //     arr[i]=1;
    //     i++;
    //     countone--;
    // }
    // while(counttwo>0){
        
    //     arr[i]=2;
    //     i++;
    //     counttwo--;
    // }

    // for(auto value:arr){
    //     cout<<value<<" ";
    // }

    // 3RD WAY BEST ONE
    //3 pointer apporach
      int start=0;
      int end=arr.size()-1;
      int i=0;
        while(i<=end){
            if(arr[i]==0){
                swap(arr[i],arr[start]);
                start++;
                i++;
            }
            else if(arr[i]==1){
               i++;
            }
            else{
                swap(arr[i],arr[end]);
                end--;
            }
                
        }
        for(auto value:arr){
            cout<<value<<" ";
        }


}

