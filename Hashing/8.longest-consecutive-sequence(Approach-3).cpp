/*

Given an unsorted array of integers nums , return the length of the longest consecutive
element  sequence

Do it in O(n) time

nums = [100,4,200,1,3,2]
Output : 4

Explanation: The longest consecutive elements sequency is [1,2,3,4] . Therefore, the length is 4



Using One Hashmap


*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, int> sequenceLength;

    int longestConsecutiveChain = 0;

    for (auto num : nums)
    {
        if (sequenceLength.find(num) == sequenceLength.end())
        {
            int leftLength = (sequenceLength.find(num - 1) != sequenceLength.end()) ? sequenceLength[num - 1] : 0;
            int rightLength = (sequenceLength.find(num + 1) != sequenceLength.end()) ? sequenceLength[num + 1] : 0;

            int totalLength = leftLength + rightLength + 1;
            sequenceLength[num] = totalLength;

            // Update the boundaries of the sequence
            if (leftLength > 0)
            {
                sequenceLength[num - leftLength] = totalLength;
            }
            if (rightLength > 0)
            {
                sequenceLength[num + rightLength] = totalLength;
            }

            longestConsecutiveChain = max(longestConsecutiveChain, totalLength);
        }
    }

    return longestConsecutiveChain;
}

int main()
{
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    vector<int> nums2 = {5, 6, 2, 15, 3, 1, 4, 12, 10, 9, 8, 11, 16};

    cout << "Longest consecutive sequence length in nums1: " << longestConsecutive(nums1) << endl;
    cout << "Longest consecutive sequence length in nums2: " << longestConsecutive(nums2) << endl;

    return 0;
}
