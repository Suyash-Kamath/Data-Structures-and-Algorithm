#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    // Colors individual components
    bool check(int start, int n, vector<vector<int>>& graph, vector<int>& col) {
        queue<int> q;
        q.push(start);
        col[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
                
                if (col[it] == -1) {
                    col[it] = !col[node];
                    q.push(it);
                }
                // If the adjacent node has the same color,
                // the graph is not bipartite.
                else if (col[it] == col[node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);

        for (int i = 0; i < n; i++) {
            if (col[i] == -1) {
                if (!check(i, n, graph, col)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n);
    cout << "Enter the adjacency matrix (row by row):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (val == 1) { // Add edge only if there is a connection
                graph[i].push_back(j);
            }
        }
    }

    Solution solution;
    if (solution.isBipartite(graph)) {
        cout << "The graph is bipartite.\n";
    } else {
        cout << "The graph is not bipartite.\n";
    }

    return 0;
}


// T.C is O(N+2E) + O(N)