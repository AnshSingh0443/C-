#include<iostream>
#include<vector>
using namespace std;

void solve(vector<string>&ans,int index,string output,vector<string>&mapping,string digits){
    //base case->index reaches the end
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }

    //ek case solve->char mapppedto curr digit ->include and exclude
    int digit=digits[index]-'0';//convert string to int
    string value=mapping[digit];//we get string mapped to the curr digit
    // now include for each char of the string
    for(int i=0;i<value.length();i++){
        char ch=value[i];
        //include
        output.push_back(ch);
        
        //R.R
        solve(ans,index+1,output,mapping,digits);

        //backtrack
        output.pop_back();

    }
}

vector<string> letterCombinations(string digits) {  
    int index=0;
    string output="";
    vector<string>ans;
    if(digits.length()==0){
        return ans;
    }
    vector<string>mapping(10);

    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    solve(ans,index,output,mapping,digits); 

    return ans;
        
}

int main(){
    //Problem statement
    // Given a string containing digits from 2-9 inclusive, 
    // return all possible letter combinations that the number could represent. Return the answer in any order.

    //maping->
    //2->abc  3->def  4->ghi 5->jkl 6->mno 7->pqrs 8->tuv 9->wxyz 

    // Example 1:

    // Input: digits = "23"
    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    // Example 2:

    // Input: digits = ""
    // Output: []
    // Example 3:

    // Input: digits = "2"
    // Output: ["a","b","c"]
    string digits="23";
    vector<string>res=letterCombinations(digits);

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<",";
    }

    return 0;


}