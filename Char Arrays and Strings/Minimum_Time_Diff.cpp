#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int findMinDifference(vector<string>& timePoints) {
    //coverting time into minutes as int and storing in a array
    vector<int>minutes;
    for(int i=0;i<timePoints.size();i++){
        string curr=timePoints[i];
        int hours=stoi(curr.substr(0,2));//taking 2 chars starting from 0th index in the curr and converting to int
        //handling circular case -METHOD 1->possibly will not work for some cases so better to go for method 
        if(hours==0){
            //instead of 00:minutes we take it as 24:minutes
            hours=24;
        }
        int minute=stoi(curr.substr(3,2));//minutes 
        int total_minutes=(hours*60)+minute;

        //push in the minutes array
        minutes.push_back(total_minutes);
    }
    // now to find the min time diff  we sort the array
    // now min diff will be minutes[i+1]-minutes[i] for each i(diff of adjcaent will be  min when sorted)
    //now we can  find min among these min diff
    sort(minutes.begin(),minutes.end());
    int mindiff=INT_MAX;
    for(int i=0;i<minutes.size() &&i+1<minutes.size();i++){
        int currdiff=minutes[i+1]-minutes[i];
        if(currdiff<mindiff){
            mindiff=currdiff;
        }
    }

    //handling circular case -METHOD 2 ie:(23:59 and 00:00 has min diff 1)
    int lastdiff=minutes[0]+1440-minutes[minutes.size()-1];
    if(lastdiff<mindiff){
        mindiff=lastdiff;
    } 
    return mindiff;
  
}
int main(){
    // problem statement:->
    // Given a list of 24-hour clock time points in "HH:MM" format, 
    // return the minimum minutes difference between any two time-points in the list
    vector<string>timePoints{"12:10","10:15","13:15","17:20","18:00","19:47","23:59"};
    
    int res=findMinDifference(timePoints);
    cout<<res;
}
