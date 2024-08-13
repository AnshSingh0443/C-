#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
    int characterReplacement(string s, int k) {
        //brute force
        //1.geenrate all substring for rach substring the len-maxxfreq would be the longest lenght if it is less than or ewal to k
        // int maxlen=0;
        // for(int i=0;i<s.length();i++){
        //     unordered_map<char,int>mp;
        //     int maxfreq=0;
        //     for(int j=i;j<s.length();j++){
        //         char ch=s[j];
        //         mp[ch]++;
        //         maxfreq=max(maxfreq,mp[ch]);
        //         if((j-i+1)-maxfreq <= k){
        //             maxlen=max(maxlen,j-i+1);
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // return maxlen;

        //2.sliding window
        int i=0;
        int j=0;
        int maxlen=0;
        unordered_map<char,int>mp;// to takee count of each char in string
        int maxfreq=0;
        //window size - maxfreq-->this gives us  the no of chars to replace in order to make the longest reapting char subbstring
        // if this is less than or equal to k(no of times we can replace)-->then it is a valid subtring
        //and len of window will be considered as a possible ans
        while(j<s.length()){
            char ch=s[j];
            mp[ch]++;

            
            maxfreq=max(maxfreq,mp[ch]);
            //valid window
            if((j-i+1)-maxfreq <= k){
                maxlen=max(maxlen,j-i+1);
            }else{
                //if not valid mindow->minimise->move i
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return maxlen;

        
    }

int main(){
    // Input: s = "AABABBA", k = 1
    // Output: 4
    // Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    // The substring "BBBB" has the longest repeating letters, which is 4.
    // There may exists other ways to achieve this answer too

    string s="AABABBA";
    int k=1;
    cout<<characterReplacement(s,k);
}