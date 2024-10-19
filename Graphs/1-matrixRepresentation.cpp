// #include<iostream>
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     // Initialize adjacency matrix with zeros
//     int adj[n+1][n+1] = {0};

//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u][v] = 1;  // Mark the edge from u to v
//         adj[v][u] = 1;  // Mark the edge from v to u (since it's an undirected graph)
//     }

//     // Print the adjacency matrix
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             cout << adj[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


// The error occurs because variable-length arrays (VLAs) cannot be initialized in this way in C++. The size of the array adj[n+1][n+1] is determined at runtime based on the input, and VLAs are not part of the C++ standard.

// To fix this, you can dynamically allocate the adjacency matrix or use a standard container like vector, which allows dynamic sizing and initialization.

// Here's a solution using vector:

// cpp
// Copy code
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Use a vector of vectors to dynamically allocate the adjacency matrix and initialize it with zeros
    vector<vector<int> > adj(n+1, vector<int>(n+1, 0));

    // Read the edges and fill the adjacency matrix
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;  // Mark the edge from u to v
        adj[v][u] = 1;  // Mark the edge from v to u (for undirected graph)
    }

    // Print the adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
// Key Changes:
// vector usage: Replaced the fixed-size array with vector<vector<int>> to dynamically handle the adjacency matrix.
// Initialization: The vector is initialized with zeros, using vector<int>(n+1, 0).
// This way, the adjacency matrix is allocated dynamically, and there will be no compile-time issues regarding variable-sized objects.