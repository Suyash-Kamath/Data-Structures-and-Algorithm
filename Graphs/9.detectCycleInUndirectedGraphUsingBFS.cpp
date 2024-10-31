#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    
private:
    bool detect(int src, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto adjNode : adj[node]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if (parent != adjNode) {
                    return true;
                }
            }
        }
        return false;
    }
    
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

int main() {
    // Example: Undirected graph represented as an adjacency list
    vector<vector<int>> adj = {
        {1},         // Node 0 is connected to Node 1
        {0, 2, 4},   // Node 1 is connected to Nodes 0, 2, and 4
        {1, 3},      // Node 2 is connected to Nodes 1 and 3
        {2, 4},      // Node 3 is connected to Nodes 2 and 4
        {1, 3}       // Node 4 is connected to Nodes 1 and 3
    };

    Solution sol;
    bool hasCycle = sol.isCycle(adj);

    if (hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
// T.C : O(N+2E) + O(N)
// SC : O(N)
