#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }

public:
    // Function to return a list containing vertices in Topological order
    vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        stack<int> st;

        // Call DFS for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        // Extract the topological order from the stack
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Create adjacency list
    vector<vector<int>> adj(V);
    cout << "Enter the edges (u v) where u -> v:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed edge from u to v
    }

    Solution obj;
    vector<int> result = obj.topologicalSort(V, adj);

    // Output the topological order
    cout << "Topological Sort Order: ";
    for (auto node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


// S.C is O(N)+O(N);
// T.C => O(V+E)