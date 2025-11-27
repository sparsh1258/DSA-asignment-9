#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<int> adj[], vector<int> &vis) {
    vis[u]=1;
    for(int v:adj[u])
        if(!vis[v]) dfs(v, adj, vis);
}

int main() {
    int V = 5;
    int E = 3;

    vector<int> adj[V];

    vector<pair<int,int>> edges = {{0,1},{1,2},{3,4}};
    for(auto &p: edges) {
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }

    vector<int> vis(V,0);
    int count = 0;

    for(int i=0;i<V;i++)
        if(!vis[i]) {
            dfs(i, adj, vis);
            count++;
        }

    cout << count;
}
