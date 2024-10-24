// BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // BFS function to explore the island
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, queue<pair<int,int>>& q, int i, int j, int n, int m) {
        // Direction vectors for moving in 4 directions (up, right, down, left)
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            vis[curr.first][curr.second] = 1;
            // Check the 4 possible directions
            for (int k = 0; k < 4; k++) {
                int nr = curr.first + dx[k];
                int nc = curr.second + dy[k];

                // If valid neighbor and part of the island
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && vis[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        int count = 0;
        // Loop through the grid to find unvisited parts of the island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If it's land and not visited
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    cout << "Island #" << count << " starting at (" << i << "," << j << ")" << endl;
                    q.push({i, j});
                    bfs(grid, vis, q, i, j, n, m);
                }
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    // Call the function and print the result
    int num_islands = sol.numIslands(grid);
    cout << "Number of islands: " << num_islands << endl;

    return 0;
}
// S.C => O(n^2)
// T.C => O(n^2) + O(n*m*5)
