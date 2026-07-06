#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int dr[], int dc[]) {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'O') {
                dfs(nr, nc, vis, board, dr, dc);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse first and last row
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, dr, dc);
            }
            if (!vis[n-1][j] && board[n-1][j] == 'O') {
                dfs(n-1, j, vis, board, dr, dc);
            }
        }

        // Traverse first and last column
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, dr, dc);
            }
            if (!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, vis, board, dr, dc);
            }
        }

        // Change all unvisited 'O' to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<char>> board(n, vector<char>(m));
    cout << "Enter the board elements row by row (O or X):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    Solution sol;
    sol.solve(board);

    cout << "Processed board:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
