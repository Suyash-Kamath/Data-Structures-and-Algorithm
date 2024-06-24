#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxLengthSubarrayDivisibleByK(vector<int> &A, int n, int K) {
    unordered_map<int, int> prefixModIndex;
    int sum = 0;
    int maxLength = 0;

    // To handle the case when the subarray starts from index 0
    prefixModIndex[0] = -1;

    for (int i = 0; i < n; i++) {
        sum += A[i];
        
        // Calculate the current prefix sum modulo K
        int mod = sum % K;
        
        // Handle negative modulo values by converting them to positive
        if (mod < 0) {
            mod += K;
        }

        // If the remainder has been seen before, update the maximum length
        if (prefixModIndex.find(mod) != prefixModIndex.end()) {
            maxLength = max(maxLength, i - prefixModIndex[mod]);
        } else {
            // Otherwise, store the first occurrence of this remainder
            prefixModIndex[mod] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> A = {2, 7, 6, 1, 4, 5};
    int n = A.size();
    int K = 3;

    cout << "Length of the largest subarray divisible by " << K << ": " << maxLengthSubarrayDivisibleByK(A, n, K) << endl;

    return 0;
}
