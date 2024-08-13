#include<iostream>
#include<vector>
using namespace std;
vector<int> sprial_print_matrix(vector<vector<int>>matrix){
    vector<int>ans;
    int m=matrix.size();//rows
    int n=matrix[0].size();//cols

    int total_elements=m*n;
    int count=0;
     
    int starting_row=0;
    int ending_col=n-1;
    int ending_row=m-1;
    int starting_col=0;

    while(count<total_elements){
        //print starting_row
        for(int col=starting_row;col<=ending_col && count<total_elements;col++){
            cout<<" "<<matrix[starting_row][col];
            ans.push_back(matrix[starting_row][col]);
            count++;
        }
        starting_row++;//this is to ensure spiral mech

        //print ending col
        for(int row=starting_row;row<=ending_row && count<total_elements;row++){
           cout<<" "<<matrix[row][ending_col];
            ans.push_back(matrix[row][ending_col]);
            count++;
        }
        ending_col--;//this is to ensure spiral mech

        //print ending row
        for(int col=ending_col;col>=starting_col && count<total_elements;col--){
            cout<<" "<<matrix[ending_row][col];
            ans.push_back(matrix[ending_row][col]);
            count++;
        }
        ending_row--;//this is to ensure spiral mech

        //print starting col
        for(int row=ending_row;row>=starting_row && count<total_elements ;row--){
            cout<<" "<<matrix[row][starting_col];
            ans.push_back(matrix[row][starting_col]);
            count++;
        }
        starting_col++;

        

    }
    return ans;

}
int main(){
    vector<vector<int>>v{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    sprial_print_matrix(v);

}