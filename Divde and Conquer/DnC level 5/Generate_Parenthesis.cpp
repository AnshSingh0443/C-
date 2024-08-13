#include<iostream>
#include<vector>
using namespace std;
void solve(vector<string>&ans,int open,int close,string output){
    // base case-> stop when all there are no brackets left and push the possible soln to ans
    if(open==0&&close==0){
        ans.push_back(output);
    }

    //include open bracket
    if(open>0){
        output.push_back('(');
        solve(ans,open-1,close,output);// since a open bracket is use we call fxn with open-1
        //backtrack
        output.pop_back();
    }

    //Include close bracket->can be included only if count of open bracket in output string is more than close bracket->(close>open->open is included more than closed)
    // here we consider the open and close in terms of remaining brackets and not count present in string that is why we use close>open instead of open>close
    if(close>open){
        output.push_back(')');
        solve(ans,open,close-1,output);
        //backtrack
        output.pop_back();
    }


}
vector<string> generateParenthesis(int n) {
    vector<string>ans;
    int open=n;
    int close=n;
    string output="";
    solve(ans,open,close,output);

    return ans;
        
}
int main(){
    int n=3;
    vector<string>res=generateParenthesis(n);

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<",";
    }

}