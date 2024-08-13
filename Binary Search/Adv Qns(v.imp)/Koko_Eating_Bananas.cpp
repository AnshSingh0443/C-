#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        //taking ceiling value
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
// ALGORITHM->    
// 1.First, we will find the maximum element in the given array i.e. max(a[]).
// 2.Place the 2 pointers i.e. low and high: Initially, we will place the pointers. 
//      The pointer low will point to 1 and the high will point to max(a[]).
// 3.Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
//   mid = (low+high) // 2 ( ‘//’ refers to integer division)
// 4.Eliminate the halves based on the time required if Koko eats ‘mid’ bananas/hr:
//       We will first calculate the total time(required to consume all the bananas in the array)
//       i.e. totalH using the function calculateTotalHours(a[], mid):
//       4.1->If totalH <= h: On satisfying this condition, we can conclude that the number ‘mid’ is one of our possible answers.
//                 But we want the minimum number. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
//       4.2->Otherwise, the value mid is smaller than the number we want(as the totalH > h).
//             This means the numbers greater than ‘mid’ should be considered and the right half of ‘mid’ consists of such numbers. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
// 5.Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}