#include <iostream>
#include <vector>

int countPairsWithDifference(std::vector<int>& nums, int k) {
    const int MAX_VAL = 100;
    std::vector<int> freq(MAX_VAL + 1, 0);
    int count = 0;

    for (int num : nums) {
        freq[num]++;
    }

    for (int i = k + 1; i <= MAX_VAL; i++) {
        count += freq[i] * freq[i - k];
    }

    return count;
}

int main() {
    std::vector<int> nums = {1, 2, 2, 1};
    int k = 1;
    std::cout << "Number of pairs with absolute difference " << k << ": " << countPairsWithDifference(nums, k) << std::endl;
    return 0;
}


/*

Count Sort Approach
We initialize a frequency array freq of size 101 (since elements are between 1 to 100).
We populate the frequency array by counting occurrences of each element in the input array.
We iterate through the frequency array starting from k + 1 to avoid negative indexing.
For each valid index, we calculate the number of pairs by multiplying the frequencies 
of the current element and the element that is k positions behind.
Both approaches provide a time complexity of 
𝑂
(
𝑁
)
O(N), where 
𝑁
N is the number of elements in the input array. The hashmap approach has an additional 
space complexity due to the hashmap, while the count sort approach uses a fixed-size frequency array.


*/


