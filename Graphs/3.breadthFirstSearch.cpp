#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Use vector instead of a variable-length array
        vector<int> vis(V, 0);  // Initializes a vector of size V with all elements as 0
        vis[0] = 1; 
        queue<int> q;
        // Push the initial starting node 
        q.push(0); 
        vector<int> bfs; 
        // Iterate till the queue is empty 
        while(!q.empty()) {
           // Get the topmost element in the queue 
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            // Traverse for all its neighbours 
            for(auto it : adj[node]) {
                // If the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector<int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector<int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}

// s.c is O(3N) => O(N)
// T.C => node oes once into bfs , and runs all its neighbours  , it runs on all its degrees , I can say that O(N+2E)
// as for every node it will traverse all its neibouring nodes