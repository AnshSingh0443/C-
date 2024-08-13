#include<iostream>
#include<vector>
using namespace std;

//recursion->T.C->o(2^cost.size())
int mincostTravel_REC(vector<int>& days, vector<int>& costs,int i){
    if(i>=days.size()){
        return 0;
    }

    //1 Day pass used
    int cost1=costs[0]+mincostTravel_REC(days,costs,i+1);

    //7 day pass used
    int passEndDay=days[i]+7-1;
    int j=i;
    while(days[j]<=passEndDay && j<days.size()){
        j++;
    }
    int cost7=costs[1]+mincostTravel_REC(days,costs,j);
    
    //30 day pass
    passEndDay=days[i]+30-1;
    j=i;
    while(days[j]<=passEndDay && j<days.size()){
        j++;
    }
    int cost30=costs[2]+mincostTravel_REC(days,costs,j);

    return min(cost1,min(cost7,cost30));
}
//2.Memoization
int mincostTravel_TOPDOWN(vector<int>& days, vector<int>& costs,int i,vector<int>&dp){
    if(i>=days.size()){
        return 0;
    }
    //step 2:check for ans in dp
    if(dp[i]!=-1){
        return dp[i];
    }

    //1 Day pass used
    int cost1=costs[0]+mincostTravel_TOPDOWN(days,costs,i+1,dp);

    //7 day pass used
    int passEndDay=days[i]+7-1;
    int j=i;
    while(days[j]<=passEndDay && j<days.size()){
        j++;
    }
    int cost7=costs[1]+mincostTravel_TOPDOWN(days,costs,j,dp);
    
    //30 day pass
    passEndDay=days[i]+30-1;
    j=i;
    while(days[j]<=passEndDay && j<days.size()){
        j++;
    }
    int cost30=costs[2]+mincostTravel_TOPDOWN(days,costs,j,dp);

    dp[i] = min(cost1,min(cost7,cost30));

    return dp[i];
}

    //3.Tabulation
    int mincostTravel_BOTTOMUP(vector<int>& days, vector<int>& costs){
        //step 1 : create a dp array
        vector<int>dp(days.size()+1,0);
        dp[days.size()]=0;

        //step 2 : base case handled

        //step 3 :reverse of top down approach
        for(int i=days.size()-1;i>=0;i--){
            //change rec calls to dp and use loop variables
            //1 Day pass used
            int cost1=costs[0]+dp[i+1];

            //7 day pass used
            int passEndDay=days[i]+7-1;
            int j=i;
            while(days[j]<=passEndDay && j<days.size()){
                j++;
            }
            int cost7=costs[1]+dp[j];
            
            //30 day pass
            passEndDay=days[i]+30-1;
            j=i;
            while(days[j]<=passEndDay && j<days.size()){
                j++;
            }
            int cost30=costs[2]+dp[j];

            
            dp[i]=min(cost1,min(cost7,cost30));

        }
        return dp[0];
    }


    // int sub(vector<int> &day, vector<int> &cost, int si)    // subproblem
    // {
    //     int n = day.size();
    //     if(si>=n)   return 0;
        
    //     if(dp[si])  return dp[si];      // ie we aready knows the answer so no need to re calculate , return answer.
        
    //     int cost_day = cost[0] + sub(day , cost , si+1);
        
    //     int i;
    //     for(i = si ; i<n and day[i]<day[si]+7 ; i++);
    //     int cost_week = cost[1] + sub(day, cost, i);
        
    //     for(i = si ; i<n and day[i]<day[si]+30 ; i++);
    //     int cost_month = cost[2] + sub(day, cost, i);     
        
    //     dp[si] = min({cost_day, cost_week , cost_month  });   // we store answer for future references 
        
    //     return dp[si];
    // } 


                
int mincostTickets(vector<int>& days, vector<int>& costs) {
    int i=0;
    // return mincostTravel_REC(days,costs,i);
    //step 1 :create a dp array
    vector<int>dp(days.size(),-1);
    return mincostTravel_TOPDOWN(days,costs,i,dp);
    
        
}

int main(){

    // Input: days = [1,4,6,7,8,20], costs = [2,7,15]
    // Output: 11
    // Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
    // On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
    // On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
    // On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
    // In total, you spent $11 and covered all the days of your travel.
    vector<int>days{1,4,6,7,8,20};

    vector<int>costs{2,7,15};

    cout<<"min cost req to travel days :->"<<mincostTickets(days,costs)<<endl;





}