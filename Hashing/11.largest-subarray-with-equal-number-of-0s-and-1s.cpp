/*

Given an array of 0s and 1s . Find the length of the largest subarray with 
equals number of 0s and 1s

Example 1:

Input :

N = 4
A[] = {0,1,0,1}
Output : 4

Explanation : The array from index [0..3]
contains equal number of 0s and 1s.
Thus the maximum length of the subarray having 
equal number of 0s and 1s is 4

*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxLengthEqual01(vector<int> &A, int n) {
    unordered_map<int, int> prefixSumIndex;
    int sum = 0;
    int maxLength = 0;

    // Convert all 0s to -1s
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            A[i] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        sum += A[i];

        // If the sum is zero, the subarray from 0 to i has equal 0s and 1s
        if (sum == 0) {
            maxLength = i + 1;
        }

        // If sum is found in the map, it means there is a subarray with equal number of 0s and 1s
        if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
            maxLength = max(maxLength, i - prefixSumIndex[sum]);
        } else {
            // Otherwise, store the sum with its index
            prefixSumIndex[sum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> A = {0, 1, 0, 1};
    int n = A.size();

    cout << "Length of the largest subarray with equal number of 0s and 1s: " << maxLengthEqual01(A, n) << endl;

    return 0;
}
