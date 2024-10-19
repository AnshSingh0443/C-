#include<iostream>
#include<vector>
#include<queue>
#include <math.h>

using namespace std;

    long long maxKelements(vector<int>& nums, int k) {
        //max heap
        long long int ans=0;
        priority_queue<int>pq;
        for(auto i:nums){
            pq.push(i);
        }
        while(k--){
            //apply operation on largest to obatain the max score
            int max_element=pq.top();
            ans+= max_element;
            pq.pop();
            pq.push(ceil(max_element/3.0));

        }
        return ans;
        
    }

int main(){

}