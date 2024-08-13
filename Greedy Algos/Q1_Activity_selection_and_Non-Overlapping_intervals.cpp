#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
  return a.second < b.second;
}
//https://leetcode.com/problems/non-overlapping-intervals/
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //make  vector of pair ->{start,end}
        vector<pair<int,int>>data;

        for(int i=0;i<intervals.size();i++){
            int first=intervals[i][0];
            int second=intervals[i][1];
            data.push_back({first,second});
        }
        //sort this based on ending point of interval
        sort(data.begin(),data.end(),cmp);

        int count=1;
        int lastend=data[0].second;
        for(int i=1;i<data.size();i++){
            if(data[i].first >= lastend){
                count++;
                lastend=data[i].second;
            }
        }

        int res=data.size()-count;
        return res;

        
    }

int solve(int n, int arr[], int dept[]) {
  vector< pair<int, int> > data;
  for(int i=0; i<n; i++) {
    data.push_back({arr[i], dept[i]});
  }

  sort(data.begin(), data.end(), cmp);


  int cnt = 1;
  cout << data[0].first << ", "<< data[0].second << endl;
  int lastDept = data[0].second;
  for(int i=1; i<n; i++) {
    if(data[i].first >= lastDept) {
      //current train can be included
      cnt++;
      lastDept = data[i].second;
      cout << data[i].first << ", "<< data[i].second << endl;    }
  }
  return cnt;
}

int main() {
  int n = 4;
  int arr[] = {5,8,2,4};
  int dept[] = {7,11,6,5};

  int ans = solve(n, arr, dept) ;
  cout << "Answer is:  " << ans << endl;

  //non -overlapping intervals->leetcode
    // Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
    // Output: 1
    // Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
    vector<vector<int>>intervals{{1,2},{2,3},{3,4},{1,3}};
    cout<<"no of interval to remove:"<<eraseOverlapIntervals(intervals);



  return 0;
}