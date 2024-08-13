#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(int n, int x, int y, int z ) {
    //here n->call for fxn  solve(n)->represents the max no of segments for length n
  //base case
  if(n == 0) {
    return 0;
  }

  if(n < 0) {
    return INT_MIN; 
  }

    int ans1 = solve(n-x, x,y,z) + 1;//->solve(n-x)->max no of segments for length n-x
    int ans2 = solve(n-y, x,y,z) + 1;//->solve(n-y)->max no of segments for length n-y
    int ans3 = solve(n-z, x,y,z) + 1;//->solve(n-z)->max no of segments for length n-z
    //why +1?
    //->beacuse ans1 gives the answer(max no of segments) of n-x and not n thus in order to get the answer for n we just add +1
    //->same case for ans2->n-y and ans3->n-z

    int ans = max(ans1, max(ans2, ans3));
    return ans;


}

int main() {
  int n = 7;
  int x = 5;
  int y = 2;
  int z = 2;

  //solve function -> returns maximum number of segments
  int ans = solve(n,x,y,z);
  //ans -> valid && invalid

  if(ans < 0 )//->the legnth can not be obtained from the given x y and z
    ans = 0; 
  cout << "Answer is: " << ans << endl;

  return 0;
}