#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solve(){
  	int N[5];
    for (int i = 0; i < 5; ++i) {
        cin >> N[i];
    }

    unordered_map<int, int> candidateCounts;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < N[i]; ++j) {
            int candidate;
            cin >> candidate;
            candidateCounts[candidate]++;
        }
    }

    int electedCount = 0;
    for (const auto& candidateCount : candidateCounts) {
        if (candidateCount.second >= 3) {
            electedCount++;
        }
    }

    return electedCount;

	
}
  

int main() {
  
  	cout<<solve();
    
	return 0;
}
