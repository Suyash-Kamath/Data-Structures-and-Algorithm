#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    long xor_sum = 0;
    int n = nums.size();

    // XOR of all numbers
    for (int i = 0; i < n; i++) {
        xor_sum ^= nums[i];
    }

    // Find rightmost different bit (bucket)
    long rightmost = (xor_sum & (xor_sum - 1)) ^ xor_sum;

    int b1 = 0, b2 = 0;

    // Split the numbers into two groups and XOR each group
    for (int i = 0; i < n; i++) {
        if (nums[i] & rightmost) {
            b1 ^= nums[i];  // Numbers in bucket 1
        } else {
            b2 ^= nums[i];  // Numbers in bucket 2
        }
    }

    return {b1, b2};
}

int main() {
    vector<int> nums = {2, 4, 2, 14, 3, 7, 7, 3};
    vector<int> result = singleNumber(nums);

    cout << "The two single numbers are: " << result[0] << " and " << result[1] << endl;

    return 0;
}
