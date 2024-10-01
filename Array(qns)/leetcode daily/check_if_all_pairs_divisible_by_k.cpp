#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        //no of pairs=n/2
        //so a pair (a,b) valid if it is divisible by k
        //another meaning a % k=r1 and b % k=r2 so r1+r2=k


        //steps
        //1 find the remainders and their count for the array->keep track using map
        //2 now we know that x % k= 0 to k-1
        //3 if rem=1 exisit only possible pair will be k-1 as k+1-1=k find it if exisit->valid pair
        //4 similarly if rem=2 only possible pair  will be k-2 as k+2-2=k
        //5 if we get a rem such that its k-rem does not exisit->return false

        //edge case if in map rem=0 check its count it should be even so that we can make all the pairs

        vector<int>mp(k,0);
        //index->rem and value->freq of rem

        for(auto &num:arr){
            int rem= ((num % k) + k) % k;//handling negative no
            //update in map
            mp[rem]++;
        }

        //edge case
        if(mp[0]%2!=0){
            return false;
        }

        for(int rem=1;rem<=k/2;rem++){
            int counterHalf=k-rem;\
            //ie there freq are not same meaning all pairs  cannot be made
            if(mp[counterHalf]!=mp[rem]){
                return false;
            }
        }
        return true;
        
    }
};

int main(){

}