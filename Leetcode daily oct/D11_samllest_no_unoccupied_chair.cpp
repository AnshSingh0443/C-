#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


int smallestChair_BRUTE_FORCE(vector<vector<int>>& times, int targetFriend) {
        //friends 0 to n-1
        //chairs 0  to INFINITY we need only n chairs so 0 t n
        //BRUTE FORCE
        int target_friend_arrival_time=times[targetFriend][0];
        //sort based onarrival time
        sort(times.begin(),times.end());
        int n=times.size();
        vector<int>chairTime(n);//will store the dep time or time when ith chairr will be free

        for(vector<int>&time:times){
            int arrival=time[0];
            int dep=time[1];

            //assign chair
            for(int i=0;i<n;i++){
                if(chairTime[i] <= arrival){
                    chairTime[i]=dep;//save dep time

                    //check if this is the target friend
                    if(target_friend_arrival_time == arrival){
                        //target firend found and assigned chair -> return its index
                        return i;
                    }
                    break;
                    //break out of for loop as a chair is assigned
                }
            }
        }

        return 0;

        
    }

    typedef pair<int, int> P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n = times.size();
        //min heap->on deptime
        priority_queue<P, vector<P>, greater<P> > occupied; //{departTime, chairNo}
        priority_queue<int, vector<int>, greater<int>> free; //min heap of unoccupied chairs
        
        int targetFriendArrival = times[targetFriend][0];
		
        //Sort based on arrival time
        sort(times.begin(),times.end());
        
		int chairNo = 0;

        for(int i = 0; i < n; i++) {
            int arrival  = times[i][0];
            int depart   = times[i][1];
            
            //free chairs accordingly
            while(!occupied.empty() && occupied.top().first <= arrival) {
                free.push(occupied.top().second); //this chair is now free
                occupied.pop();
            }

            if(free.empty()) {
                occupied.push({depart, chairNo});

                if(arrival == targetFriendArrival)
                    return chairNo;

                chairNo++;
            } else {
                int leastChairAvailable = free.top();
                free.pop();
                if(arrival == targetFriendArrival) {
                    return leastChairAvailable;
                }
                occupied.push({depart, leastChairAvailable});
            }
        }

        return -1;
    }
int main(){

}