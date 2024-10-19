#include<iostream>
using namespace std;



int main(){

    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for (int  i = 0; i < m; i++)
    {
       int u,v;
       // if it is directed graph , there is only edge between u and v so no need of adj[v].push_back(u) and space complexity is O(E);
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
       


    return 0;
}