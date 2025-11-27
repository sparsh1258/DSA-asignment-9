#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
void bfs(int start,vector<int> adj[],int n){
    vector<int> vis(n,0);
    queue<int> q;
    vis[start]=1;
    q.push(start);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u]){
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
void dfsutil(int u,vector<int> adj[],vector<int>&vis){
    vis[u]=1;
    cout<<u<<" ";
    for(int v:adj[u])
    if(!vis[v]) dfsutil(v,adj,vis);
}
void dfs(int start,vector<int> adj[],int n){
    vector<int> vis(n,0);
    dfsutil(start,adj,vis);
}
struct edge{int u,v,w;};
struct DSU{
    vector<int> p,r;
    DSU(int n):p(n),r(n,0){for(int i=0;i<n;i++)p[i]=i;
    }int find(int x){return p[x]==x ? x:p[x]=find(p[x]);
    }
void unite(int a,int b){
    a=find(a);b=find(b);
if(a!=b){
    if(r[a]<r[b]){
        swap(a,b);
        p[b]=a;
        if(r[a]==r[b])r[a]++;
    }
}}};
void krushkal(int n,vector<edge> &edges){
    sort(edges.begin(),edges.end(),[](auto &a,auto &b){reuturn a.w<b.w;});
    DSU dsu(n);
    int total =0;
    for(auto &e:edges){
        if(dsu.find(e.u)!=dsu.find(e.v)){
            dsu.unite(e.u,e.v);
            cout<<e.u<<" "<<e.v<<" "<<e.w<<"\n";
            total+= e.w ;
           }
    }
    cout<<"total"<<total<<"\n ";
}
void prim(int n, vector<pair<int,int>> adj[]) {
    vector<int> key(n, INT_MAX), vis(n,0), parent(n,-1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    key[0]=0;
    pq.push({0,0});

    while(!pq.empty()) {
        int u=pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;

        for(auto &p:adj[u]) {
            int v=p.first, w=p.second;
            if(!vis[v] && w<key[v]) {
                key[v]=w;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
    }

    int total=0;
    for(int i=1;i<n;i++) {
        cout<<parent[i]<<" "<<i<<" "<<key[i]<<"\n";
        total+=key[i];
    }
    cout<<"Total "<<total<<"\n";
}

void dijkstra(int n, vector<pair<int,int>> adj[], int src) {
    vector<int> dist(n, INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});

    while(!pq.empty()) {
        int u=pq.top().second;
        pq.pop();
        for(auto &p:adj[u]) {
            int v=p.first, w=p.second;
            if(dist[u]+w < dist[v]) {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<i<<" "<<dist[i]<<"\n";
}
int main(){
    
}