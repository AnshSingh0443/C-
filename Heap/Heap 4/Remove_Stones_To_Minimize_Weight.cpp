#include<iostream>
#include<queue>
#include<vector>

using namespace std;
    int minStoneSum(vector<int>& piles, int k) {
        // Create a max heap
        priority_queue<int>maxHeap;
        // Push the elements in max heap
        for(int i = 0;i<piles.size();i++){
            maxHeap.push(piles[i]);
        }
        // Now perform the operations for k times
        while(k--){
            // Fetch top element
            int topElement = maxHeap.top();
            // Remove that element
            maxHeap.pop();
            // Reduce the top element 
            topElement = topElement - topElement/2;
            // Push the topElement in maxHeap again
            maxHeap.push(topElement);
        }
        // Sum of the max heap elements
        int sum = 0;
        while(!maxHeap.empty()){
            int element = maxHeap.top();
            sum = sum + element;
            maxHeap.pop();
        }
        return sum;
    }

int main(){
    int k =3;
    vector<int>piles={5,8,11,12};
    //1 op of 12->6
    //1 op on 11->6
    //1 op on 8->4
    //final max heap->6,6,5,4 sum=21(min stones)
    cout<<minStoneSum(piles,k)<<" ";

}