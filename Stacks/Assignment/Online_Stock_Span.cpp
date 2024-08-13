#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class StockSpanner {  
public:
    vector<int>prices;
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    //brute force
    int next0(int price) {
        //push the current day price 
        prices.push_back(price);

        //calculatee the span for this current day price
        //index of current day price->prices.size()-1
        
        int span=0;
        int i=prices.size()-1;
        while( i>=0 && prices[i]<=price){
            span=span+1;
            i--;
        }

        return span;
        
    }
    //optimal using stack
    int next(int price){
        int span=1;

        while(!st.empty() && st.top().first <=price){
            span=span+st.top().second;
            st.pop();
        }
        st.push({price,span});

        return st.top().second;

    }
};
int main(){
    StockSpanner *stockSpanner = new StockSpanner();
    cout<<stockSpanner->next(100); // return 1
    cout<<stockSpanner->next(80);  // return 1
    cout<<stockSpanner->next(60);  // return 1
    cout<<stockSpanner->next(70);  // return 2
    cout<<stockSpanner->next(60);  // return 1
    cout<<stockSpanner->next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    cout<<stockSpanner->next(85);  // return 6

}



/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


// Example 1:

// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]

// Explanation
// StockSpanner stockSpanner = new StockSpanner();
// stockSpanner.next(100); // return 1
// stockSpanner.next(80);  // return 1
// stockSpanner.next(60);  // return 1
// stockSpanner.next(70);  // return 2
// stockSpanner.next(60);  // return 1
// stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
// stockSpanner.next(85);  // return 6