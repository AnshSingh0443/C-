#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //kitna petrol kam pd gaya;
        int deficit=0;
        //kitna petrol hai
        int balance=0;
        //initial starting station
        int start=0;

        for(int i=0;i<gas.size();i++){
            //current petrol nikalo->balance(purana kitna hai + travel kare toh kitna bacha(gas[i]-cost[i]))
            balance += gas[i]-cost[i];

            if(balance<0){
                //matlab we could not travel and now this is deficit of petrol we needed
                deficit +=balance;
                //instead of starting again from start+1 we start from where we failed
                start=i+1;
                //starting a new so reset balance
                balance=0;
            }
            
        }
         if(balance+deficit>=0){
                return start;
        }else{
                return -1;
        }
        
}
 
int main(){
    //gas = [1,2,3,4,5], cost = [3,4,5,1,2]
    vector<int>gas={1,2,3,4,5};
    vector<int>cost={3,4,5,1,2};

    cout<<canCompleteCircuit(gas,cost);

}