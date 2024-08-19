#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int celeb(vector<vector<int>>&M,int n){
    //stack
    stack<int>st;
    //1.push all person onto stack
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size()!=1){
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        if(M[a][b]){
            // a knows b->a cannot be celeb but b might be
            st.push(b);
        }else{
            //a does not know b->b cannot be celeb but a might be
            st.push(a);
        }
    }
    //stack has only 1 elemm which might be a celeb
    int mightBeCeleb=st.top();
    st.pop();

    //check if celeb
    //1.all  row elem->0 cleb does not know anyone
    for(int col=0;col<n;col++){
        if(M[mightBeCeleb][col]!=0){
            return -1;
        }
    }
    //2.all col should 1 one expect diagonal/self ->everyone know  him
    for(int row=0;row<n;row++){
        if(M[row][mightBeCeleb]!=1 && row!=mightBeCeleb){
            return -1;
        }
    }

    //mightbeceleb is a celeb
    return mightBeCeleb;

}

int main(){
// A celebrity is a person who is known to all but does not know anyone at a party.
// A party is being organized by some people. 
// A square matrix mat is used to represent people at the party
// such that if an element of row i and column j is set to 1 it means ith person knows jth person. 
//You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

// Note: Follow 0-based indexing.

// Examples:

// Input: mat[][] = [[0 1 0],
//                 [0 0 0], 
//                 [0 1 0]]
// Output: 1
// Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
    vector<vector<int>>M={
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };
    int n=3;

    cout<<celeb(M,n);


}