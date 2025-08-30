#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, graph, vis, pathVis, check)) {
                    check[node] = 0;
                    return true;
                }
            } else if (pathVis[it]) {
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        vector<int> safeNodes;

        // Perform DFS for each node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }

        // Collect all safe nodes
        for (int i = 0; i < V; i++) {
            if (check[i] == 1) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};

int main() {
    // Input graph
    vector<vector<int>> graph = {
        {1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}
    };

    // Create Solution object
    Solution solution;

    // Get the eventual safe nodes
    vector<int> safeNodes = solution.eventualSafeNodes(graph);

    // Print the result
    cout << "Eventual Safe Nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
