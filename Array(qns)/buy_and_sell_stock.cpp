#include<iostream>
#include<vector>
using namespace std;
//BRUTE FORCE
int stock(vector<int>prices){
    int buy=INT_MAX;
    int sell=INT_MIN;
    int profit=0;
    int max_profit=0;

    for(int i=0;i<prices.size();i++){
        int num=prices[i];
        if(num<buy){
            buy=num;
        }
        for(int j=i+1;j<prices.size();j++){
            int num2=prices[j];
            if(num2>sell){
                sell=num2;
            }
            profit=sell-buy;
            if(profit>max_profit){
                max_profit=profit;
            }
            if(max_profit<=0){
                return 0;
            }
        }
       
    }
    return max_profit;
}
int main(){
    vector<int>prices{7,6,5,4,3,2,1};
    int result=stock(prices);
    if(result==0){
        cout<<"no profit can be made";

    }else{
        cout<<"max profit is "<<result;

    }
}