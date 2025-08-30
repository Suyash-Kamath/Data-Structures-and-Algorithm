#include <iostream>
#include <vector>
#include <set>
#include <utility> // For pair
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, 
             vector<vector<int>>& vis, vector<pair<int, int>>& vec, 
             int row0, int col0) {
        vis[row][col] = 1;
        vec.push_back({row - row0, col - col0}); // Normalize the coordinates

        int n = grid.size();
        int m = grid[0].size();

        // Direction vectors for moving up, left, down, and right
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            // Check bounds and conditions for unvisited land cell
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, grid, vis, vec, row0, col0);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st; // To store unique shapes of islands

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec; // To store the shape of the island
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec); // Insert the shape into the set
                }
            }
        }

        return st.size(); // The number of distinct island shapes
    }
};

int main() {
    int n, m;
    cout << "Enter the dimensions of the grid (n rows, m columns): ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the grid values (0 for water, 1 for land):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int result = obj.countDistinctIslands(grid);
    cout << "The number of distinct islands is: " << result << endl;

    return 0;
}

// T.C =>O(N*M)*O(log n*m)+ O(N*M*4)
// S.C => O(N*M)