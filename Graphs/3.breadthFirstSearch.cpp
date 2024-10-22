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
// T.C => node goes once into bfs , and runs all its neighbours  , it runs on all its degrees , I can say that O(N+2E)
// as for every node it will traverse all its neibouring nodes

/*

Yes, you can declare a parameter as vector<int> adj[], but it's important to understand how it works and its implications in C++.

Explanation:
vector<int> adj[] is an array of vector<int>, where each element of the array is a vector<int>. This is typically used to represent an adjacency list for a graph.
However, in C++, when you pass an array to a function, it decays to a pointer, meaning that the function will not know the size of the array. Therefore, you need to handle the size separately, typically by passing it as an additional parameter.

When you write an addEdge function that takes vector<int> adj[] (or vector<vector<int>>& adj) as a parameter, it is important to understand how C++ handles passing arrays and references.

1. Array Behavior in C++:
When you pass an array to a function in C++, it decays to a pointer. Therefore, modifications made to the elements of the array within the function will affect the original array.
However, if you pass the array as a copy (like vector<int> adj[] without specifying a reference), it won’t be directly a copy but a pointer, meaning you are modifying the original array.

Key Takeaways:
Changes Reflect: Since you are passing the array of vectors (as a pointer), any changes made inside the addEdge function will reflect in the original adj variable.
Call by Reference: In the case of using vector<vector<int>>& adj, it’s clear you are working with a reference, and all changes will naturally be reflected in the original vector.
Functionality: The addEdge function effectively updates the adjacency list by adding edges between the specified vertices.
Conclusion:
To summarize, as long as you pass the adjacency list (either as an array of vectors or by reference), any updates made in the addEdge function will reflect in the original data structure used in the main function. Let me know if you need any further clarification!

 */