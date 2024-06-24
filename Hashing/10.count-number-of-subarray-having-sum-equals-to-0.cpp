#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countZeroSumSubarrays(vector<int> &A, int n) {
    unordered_map<int, int> prefixSumFrequency;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];

        // If the sum is zero, we found a subarray with sum 0
        if (sum == 0) {
            count++;
        }

        // If the sum is found in the map, it means there are subarrays with sum 0
        if (prefixSumFrequency.find(sum) != prefixSumFrequency.end()) {
            count += prefixSumFrequency[sum];
        }

        // Increment the frequency of the current sum in the map
        prefixSumFrequency[sum]++;
    }

    return count;
}

int main() {
    vector<int> A = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = A.size();

    cout << "Number of subarrays with 0 sum: " << countZeroSumSubarrays(A, n) << endl;

    return 0;
}
