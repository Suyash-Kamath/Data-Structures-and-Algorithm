#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    // Colors individual component
    bool dfs(int start, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[start] = col;

        for (auto it : graph[start]) {
            // If the adjacent node is not yet colored
            if (color[it] == -1) {
                // Recursively color with the opposite color
                if (!dfs(it, !col, color, graph)) {
                    return false;
                }
            }
            // If the adjacent node has the same color
            else if (color[it] == col) {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // Initialize all nodes as uncolored

        for (int i = 0; i < n; i++) {
            // If the node is uncolored, start a DFS
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);

    cout << "Enter edges (u, v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Since it's an undirected graph
    }

    Solution sol;
    if (sol.isBipartite(graph)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
