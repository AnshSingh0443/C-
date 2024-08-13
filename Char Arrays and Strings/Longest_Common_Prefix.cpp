#include<iostream>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    string ans;
    int i=0;
    while(true){
        char curr_ch=0;
        for(auto str:strs){
            //for each string in strs
            if(i>=str.length()){
                //out of bound
                curr_ch=0;
                break;
            }
            //first one
            if(curr_ch==0){
                curr_ch=str[i];//curr_ch=f
            }
            else if(curr_ch!=str[i]){
                curr_ch=0;
                break;
            }

        }
        if(curr_ch==0){
            break;
        }
        ans.push_back(curr_ch);
        i++;
    }
    return ans;
}

int main(){
    // EXAMPLE
    // Input: strs = ["flower","flow","flight"]
    // Output: "fl"
    vector<string>strs{"flower","flow","flight"};
    cout<<longestCommonPrefix(strs);

}