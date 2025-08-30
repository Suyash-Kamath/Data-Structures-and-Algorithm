#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        int ans = 0;
        int up, down, left, right;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < column; c++) {
                if (grid[r][c] == 1) {
                    if (r == 0) up = 1;
                    else up = grid[r - 1][c] == 0;

                    if (c == 0) left = 1;
                    else left = grid[r][c - 1] == 0;

                    if (r == row - 1) down = 1;
                    else down = grid[r + 1][c] == 0;

                    if (c == column - 1) right = 1;
                    else right = grid[r][c + 1] == 0;

                    ans += up + down + left + right;
                }
            }
        }
        return ans;
    }
};

int main() {
    // Sample input: 2D grid representing the map
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    Solution sol;
    int perimeter = sol.islandPerimeter(grid);
    cout << "Island Perimeter: " << perimeter << endl;

    return 0;
}
