#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);

        // Calculate indegree of each node
        for (int i = 0; i < V; i++) {
            for (int it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        // Push nodes with 0 indegree into the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;

        // Perform Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            // Decrease the indegree of adjacent nodes
            for (int it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If count of nodes in topological sort is not equal to the number of nodes
        // in the graph, it means there is a cycle.
        return cnt != V;
    }
};

// Example usage
int main() {
    Solution sol;
    int V = 4; // Number of vertices
    vector<vector<int>> adj = {
        {1},    // Edges from node 0
        {2},    // Edges from node 1
        {3},    // Edges from node 2
        {1}     // Edges from node 3 (cycle)
    };

    if (sol.isCyclic(V, adj)) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
