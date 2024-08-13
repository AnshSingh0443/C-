#include<iostream>
#include<vector>
using namespace std;
    void solve(vector<int>& prices,int& buy,int& profit,int& maxprofit,int index){
        //base case
        if(index>=prices.size()){
            return;
        }

        //solve 1 case->curr day pe sell
        if(buy>prices[index]){
            buy=prices[index];
        }
        profit=prices[index]-buy;
        if(maxprofit<profit){
            maxprofit=profit;
        }
        //R.R
        solve(prices,buy,profit,maxprofit,index+1);
    }
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int profit=0;
        int maxprofit=0;
        int index=0;
        solve(prices,buy,profit,maxprofit,index);

        return maxprofit;
        

    }
int main(){
    vector<int>prices{7,1,5,3,6,4};
    cout<<maxProfit(prices);

}