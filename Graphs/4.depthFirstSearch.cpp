#include<iostream>
#include<vector>
using namespace std;

void dfs(int node , vector<int>adj[],vector<int>&visited,vector<int>&list){
    visited[node] = 1;
    list.push_back(node);
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited,list);
        }
    }
}

vector<int>dfsOfGraph(int V,vector<int> adj[]){
    
    vector<int>visited(V);
    int start =0;
    vector<int>list; // store the dfs
    dfs(start,adj,visited,list);
    
    return list;
}

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    
    vector <int> ans = dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}