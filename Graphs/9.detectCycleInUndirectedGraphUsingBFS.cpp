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



// DFS Approach
/*

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, node, vis, adj) == true) {
                    return true;
                }
            } else if (it != parent) {
                return true;
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    
    // Initialize the adjacency list
    vector<vector<int>> adj(V);
    
    cout << "Enter edges (u v) for each edge:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph, so add both ways
    }
    
    Solution solution;
    if (solution.isCycle(adj)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }
    
    return 0;
}


 */
