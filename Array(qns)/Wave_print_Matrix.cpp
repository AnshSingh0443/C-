#include<iostream>
#include<vector>
using namespace std;
void wave_print_matrix(vector<vector<int>>v){
    int m=v.size();//rows
    int n=v[0].size();//columns
    //iterate columns
    for(int col=0;col<n;col++){
        //even col
        if(col==0 || col%2==0){
            // iterate row from top to bottom
            for(int row=0;row<m;row++){
                cout<<v[row][col]<<" ";
            }
        }
        //odd col
        else{
            //iterate row form bottom to top
            for(int row=m-1;row>=0;row--){
                cout<<v[row][col]<<" ";
            }
        }
    }
}
int main(){
    // column-Even->>print top to bottom
    // column-ODD->>print bottom to top
    vector<vector<int>>v{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12,},
        {13,14,15,16},
        {17,18,19,20}
    };
    wave_print_matrix(v);
}