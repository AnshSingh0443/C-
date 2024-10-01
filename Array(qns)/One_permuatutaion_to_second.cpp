#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the longest common prefix sequence
int longest_common_prefix_length(const vector<int>& perm1, const vector<int>& perm2) {
    unordered_map<int, int> position;
    for (int i = 0; i < perm1.size(); i++) {
        position[perm1[i]] = i;
    }

    int max_length = 0, current_length = 0;
    int previous_index = -1;
    for (int i = 0; i < perm2.size(); i++) {
        if (position[perm2[i]] > previous_index) {
            current_length++;
            previous_index = position[perm2[i]];
            max_length = max(max_length, current_length);
        } else {
            current_length = 1;
            previous_index = position[perm2[i]];
        }
    }

    return max_length;
}

int min_steps_to_convert(const vector<int>& perm1, const vector<int>& perm2) {
    int n = perm1.size();
    int lcs_length = longest_common_prefix_length(perm1, perm2);
    
    // Minimum steps required to convert perm1 to perm2
    return n - lcs_length+1;
}

int main() {
    int n;
   
    n=5;

    vector<int> perm1={1,5,4,2,3};
    vector<int> perm2={1,2,3,4,5};

    int result = min_steps_to_convert(perm1, perm2);
    cout << "Minimum number of steps required: " << result << endl;

    return 0;
}
