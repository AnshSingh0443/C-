#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool rotateString_brute(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if (m != n) 
            return false;

        // Try all possible rotations of the string
        for (int rotationCount = 1; rotationCount <= m; ++rotationCount) {
            // Perform one rotation
            rotate(s.begin(), s.begin() + 1, s.end()); //it says that I want (s.begin()+1)th character to become the first character now. i.e. shifting left by one
            if (s == goal) 
                return true;
        }
        return false;
    }

    //approact to o(n) 
    bool rotateString(string s, string goal) {
        //concatinate s with s and  check if goal is present in it as a sunstring
        //s=abcde --> s+s=abcdeabcde  and goal =abced->not present->false;
        //any rotations of s will always be present in s+s
        int m = s.length();
        int n = goal.length();
        
        if(m == n && (s+s).find(goal) != string::npos)
            return true;
        
        return false; 
    }
   
};

int main(){

}