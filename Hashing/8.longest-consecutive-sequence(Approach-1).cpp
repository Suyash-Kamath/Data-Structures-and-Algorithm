/*

Given an unsorted array of integers nums , return the length of the longest consecutive 
element  sequence

Do it in O(n) time

nums = [100,4,200,1,3,2]
Output : 4

Explanation: The longest consecutive elements sequency is [1,2,3,4] . Therefore, the length is 4



0,3,7,2,5,8,4,6,0,1

0,1,2,3,4,5,6,7,8

*/


#include <iostream>
#include <vector>
#include <algorithm>

int longestConsecutive(std::vector<int>& nums) {
    if (nums.empty()) return 0;

    // Step 1: Sort the array
    std::sort(nums.begin(), nums.end());

    // Step 2: Initialize variables to track the longest sequence
    int longest_streak = 1;
    int current_streak = 1;

    // Step 3: Iterate through the sorted array to find the longest consecutive sequence
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {  // check if the current element is not equal to the previous one
            if (nums[i] == nums[i - 1] + 1) {  // check if the current element is consecutive
                current_streak++;
            } else {
                longest_streak = std::max(longest_streak, current_streak);
                current_streak = 1;  // reset current streak
            }
        }
    }

    // Step 4: Return the maximum of the longest streak found and the current streak
    return std::max(longest_streak, current_streak);
}

int main() {
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    std::cout << "Length of the longest consecutive sequence: " << longestConsecutive(nums) << std::endl;

    nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    std::cout << "Length of the longest consecutive sequence: " << longestConsecutive(nums) << std::endl;

    return 0;
}
