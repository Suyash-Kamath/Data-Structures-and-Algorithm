#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subset = (1 << nums.size());  // Total number of subsets
        vector<vector<int>> ans;  // Resultant vector of subsets
        
        for (int i = 0; i < subset; i++) {
            vector<int> list;  // Current subset
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {  // Check if the j-th bit is set in i
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);  // Add the subset to the result
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};  // Example input
    vector<vector<int>> result = solution.subsets(nums);
    
    // Print the subsets
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
