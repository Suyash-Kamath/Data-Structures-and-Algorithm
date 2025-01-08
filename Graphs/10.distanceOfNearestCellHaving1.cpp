#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // Define a predefined grid
    vector<vector<int>> grid = {
        {1, 0, 1},
        {0, 0, 0},
        {0, 0, 1}
    };

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> distance(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    // Initialize the queue and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    // Directions for moving in the grid
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // BFS to calculate distances
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        distance[row][col] = steps;

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0) {
                vis[nr][nc] = 1;
                q.push({{nr, nc}, steps + 1});
            }
        }
    }

    // Output the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
