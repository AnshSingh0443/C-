#include <iostream>
#include <queue>
using namespace std;
int signum(int a, int b)
{
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    return -1;
}
void callMedian(double &median, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int element)
{

    switch (signum(minHeap.size(), maxHeap.size()))
    {
    case 0: // Both heaps have equal size
        if (element > median)
        {
            // Push in minHeap
            minHeap.push(element);
            median = minHeap.top();
        }
        else
        {
            // Push in maxHeap
            maxHeap.push(element);
            median = maxHeap.top();
        }
        break;
    case 1: // minHeap has larger size than maxHeap
        if (element > median)
        {
            // first remove from minHeap and push to maxHeap
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            // Push new element to the minHeap
            minHeap.push(element);
            // Both have equal size so average will be median
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        else
        {
            // simply push in maxHeap
            maxHeap.push(element);
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        break;
    case -1: // maxHeap has larger size than minHeap
        if (element > median)
        {
            // simply insert in minHeap
            minHeap.push(element);
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        else
        {
            // first remove from maxHeap and push to minHeap
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            // Push new element to the maxHeap
            maxHeap.push(element);
            // Both have equal size so average will be median
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        break;
    }
}

/*
    Implement data structure that gets the median from a data stream

    Max heap of lower values & min heap of higher values, access to mids

    Time: O(log n) + O(1)
    Space: O(n)
*/
//LEETCODE
// class MedianFinder {
// public:
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         if (lower.empty()) {
//             lower.push(num);
//             return;
//         }
        
//         if (lower.size() > higher.size()) {
//             if (lower.top() > num) {
//                 higher.push(lower.top());
//                 lower.pop();
//                 lower.push(num);
//             } else {
//                 higher.push(num);
//             }
//         } else {
//             if (num > higher.top()) {
//                 lower.push(higher.top());
//                 higher.pop();
//                 higher.push(num);
//             } else {
//                 lower.push(num);
//             }
//         }
//     }
    
//     double findMedian() {
//         double result = 0.0;
        
//         if (lower.size() == higher.size()) {
//             result = lower.top() + (higher.top() - lower.top()) / 2.0;
//         } else {
//             if (lower.size() > higher.size()) {
//                 result = lower.top();
//             } else {
//                 result = higher.top();
//             }
//         }
        
//         return result;
//     }
// private:
//     priority_queue<int> lower;//maxheap
//     priority_queue<int, vector<int>, greater<int>> higher;//minheap
// };

// /**
//  * Your MedianFinder object will be instantiated and called as such:
//  * MedianFinder* obj = new MedianFinder();
//  * obj->addNum(num);
//  * double param_2 = obj->findMedian();
//  */

int main()
{
    int arr[6] = {5, 7, 2, 9, 3, 8};
    int n = 6;
    // Max - heap
    priority_queue<int> maxHeap;
    // Min - heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // Initially median is 0
    double median = 0;
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        callMedian(median, maxHeap, minHeap, element);
        cout << median << " ";
    }
    cout << endl;
    return 0;
}