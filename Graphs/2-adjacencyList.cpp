#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int nodes,edges;
    cin>>nodes>>edges;
    vector<int>adj[nodes+1];
    
    for(int i =0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
   for(int i =1;i<=nodes;i++){
       cout<< " Node "<<i<<" Neighbour is : ";
       for(auto it : adj[i]){
           cout<<it<<" ";
       }
       cout<<endl;
   }
    return 0;
}