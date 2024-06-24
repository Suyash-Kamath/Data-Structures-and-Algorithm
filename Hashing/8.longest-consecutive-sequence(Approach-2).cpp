/*

Given an unsorted array of integers nums , return the length of the longest consecutive
element  sequence

Do it in O(n) time

nums = [100,4,200,1,3,2]
Output : 4

Explanation: The longest consecutive elements sequency is [1,2,3,4] . Therefore, the length is 4



nums : 5 6 2 15 3 1 4 12 10 9 8 11 16

unordered_map<int,bool> present,checked

longestConsecutiveChain = 2

longestConsecutiveChain = 6

longestConsecutiveChain = 5

1 - 1 =0 , 0 present ? No , so 1 is starting point

1->2->3->4->5->6
8->9->10->11->12
15->16

present = {

{5,t},{15,t},{6,t},{2,t},{3,t},{1,t},{4,t},{12,t},{10,t},{9,t},{8,t},{11,t},{16,t}

}


checked ={

{15,t},{16,t},{1,t},{2,t},{3,t},{4,t},{5,t},{6,t},{8,t},{9,t},{10,t},{11,t},{12,t}

}


*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &nums)
{

    unordered_map<int, bool> present, checked;

    for (auto a : nums)
    {
        present[a] = true;
    }

    int longestConsecutiveChain = 0;

    for (auto a : nums)
    {

        if (!checked[a] && !present[a - 1])
        {
            int currentChain = 0;
            int start = a;
            while (present[start])
            {
                currentChain++;
                checked[start] = true;
                start++;
            }

            longestConsecutiveChain = max(longestConsecutiveChain, currentChain);
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

    return 0;
}

// T.C and S.C = O(2^N) => O(N)