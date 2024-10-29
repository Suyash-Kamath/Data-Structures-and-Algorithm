// Only BFS works as we have to get the work done in minimum time
/* 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Queue to store {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Directions for up, down, left, and right
        vector<pair<int, int>> direction = {
            {-1, 0}, {1, 0}, {0, 1}, {0, -1}
        };
        
        // Initialize the queue with rotten oranges and mark them in `vis`
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else {
                    vis[i][j] = 0;
                }
            }
        }
        
        int time = 0;

        // Perform BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            time = max(time, t);

            // Check all 4 possible directions
            for (auto d : direction) {
                int nrow = r + d.first;
                int ncol = c + d.second;

                // Check bounds and if the cell has a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                    && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        // Check for any remaining fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return time;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the grid values (0 for empty, 1 for fresh, 2 for rotten):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution solution;
    int result = solution.orangesRotting(grid);
    if (result == -1) {
        cout << "All oranges cannot rot." << endl;
    } else {
        cout << "Minimum time to rot all oranges: " << result << endl;
    }

    return 0;
}
*/

// using counter method

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Queue to store {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Directions for up, down, left, and right
        vector<pair<int, int>> direction = {
            {-1, 0}, {1, 0}, {0, 1}, {0, -1}
        };

        int cntFresh = 0;  // Counter for fresh oranges
        
        // Initialize the queue with rotten oranges and mark them in `vis`
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});  // Push rotten oranges with time 0
                    vis[i][j] = 2;        // Mark as visited (rotten)
                }
                else if (grid[i][j] == 1) {
                    cntFresh++;           // Count fresh oranges
                }
            }
        }
        
        int time = 0;
        int count = 0;  // To count the fresh oranges that become rotten
        
        // Perform BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            time = max(time, t);

            // Check all 4 possible directions
            for (auto d : direction) {
                int nrow = r + d.first;
                int ncol = c + d.second;

                // Check bounds and if the cell has a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                    && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    count++;  // Increment the count of rotted fresh oranges
                }
            }
        }

        // Check if all fresh oranges are rotted
        if (count != cntFresh) return -1;
        
        return time;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the grid values (0 for empty, 1 for fresh, 2 for rotten):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution solution;
    int result = solution.orangesRotting(grid);
    if (result == -1) {
        cout << "All oranges cannot rot." << endl;
    } else {
        cout << "Minimum time to rot all oranges: " << result << endl;
    }

    return 0;
}


// S.C is O(NM)
// T.C is O(NM)+ O(4NM)
// queue me push karne ka time + 4 direction ko travel
