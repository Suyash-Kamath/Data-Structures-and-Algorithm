#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxLengthSubarraySumK(vector<int> &A, int n, int K) {
    unordered_map<int, int> prefixSumIndex;
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];

        // If the sum is equal to K, update maxLength to the current index + 1
        if (sum == K) {
            maxLength = i + 1;
        }

        // If (sum - K) is found in the map, it means there is a subarray with sum K
        if (prefixSumIndex.find(sum - K) != prefixSumIndex.end()) {
            maxLength = max(maxLength, i - prefixSumIndex[sum - K]);
        }

        // If the sum is not found in the map, store the current index
        if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
            prefixSumIndex[sum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> A = {10, 5, 2, 7, 1, 9};
    int n = A.size();
    int K = 15;

    cout << "Length of the largest subarray with sum " << K << ": " << maxLengthSubarraySumK(A, n, K) << endl;

    return 0;
}
