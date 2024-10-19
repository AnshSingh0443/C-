#include<iostream>
#include<vector>

using namespace std;
    long long minimumSteps(string s) {
        //logic
        //iteratate thrpough the string
        //whenever a 0 is encountered ->no of swaps req to shift thayt 0 to the right = no of black(1s) encountered till then
        //so swaps+=no of blacks/1s
        long long int swaps =0;
        int black=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                swaps+=black;
            }else{
                black++;
            }
        }
        return swaps;

    }

int main(){

}