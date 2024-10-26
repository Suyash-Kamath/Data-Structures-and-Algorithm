// Using Adjacency Matrix
/*
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        visit[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visit[i]) {
                dfs(i, isConnected, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                dfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
};

int main() {
    // Example adjacency matrix representing connected components
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution sol;
    int result = sol.findCircleNum(isConnected);
    
    // Output the result
    cout << "Number of connected components (circles): " << result << endl;

    return 0;
}
*/

// Convert Matrix into List and solve

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adjList[], vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adjList[node]) {
            if (!visited[it]) {
                dfs(it, adjList, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjList[n];

        // Build adjacency list from adjacency matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> visited(n, 0);
        int cnt = 0;

        // Find connected components using DFS
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, adjList, visited);
            }
        }

        return cnt;
    }
};

int main() {
    // Example adjacency matrix representing connected components
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution sol;
    int result = sol.findCircleNum(isConnected);
    
    // Output the result
    cout << "Number of connected components (circles): " << result << endl;

    return 0;
}

// S.C is O(N)
// T.c is O(N) + O(N+2E)


// BFS

/*

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(int node , vector<int>adjList[],vector<int>&visited){
    visited[node]=1;
    queue<int>q;
    q.push(node);
    
    while(!q.empty()){
        int nodes = q.front();
        q.pop();
        for(auto it:adjList[nodes]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    
    
}

int findCount(int V, vector<vector<int>>&isConnected){
    //convert into adjList;
    
    vector<int>adjList[V];
    vector<int>visited(V,0);
    
    for(int i =0;i<V;i++){
        for(int j =0;j<V;j++){
            if(isConnected[i][j]==1 && i!=j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    
    int count =0;
    
    for(int i =0;i<V;i++){
        if(!visited[i]){
            count++;
            bfs(i,adjList,visited);
        }
    }
    return count;
}

int main(){
    
    vector<vector<int>>isConnected = {
        {1,1,0},{1,1,0},{0,0,1}
    };
    
    int V = isConnected.size();
    
    int result = findCount(V,isConnected);
    
    cout<<result;
    
    return 0;
}
 */
