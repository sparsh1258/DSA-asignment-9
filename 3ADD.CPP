#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int N = 4;
    int K = 2;

    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    vector<vector<pair<int,int>>> adj(N+1);
    for(auto &t: times)
        adj[t[0]].push_back({t[1], t[2]});

    vector<int> dist(N+1, INT_MAX);
    dist[K] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, K});

    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int cost = p.first;
        int u = p.second;

        if(cost > dist[u]) continue;

        for(auto &e: adj[u]) {
            int v = e.first, w = e.second;
            if(cost + w < dist[v]) {
                dist[v] = cost + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=N;i++) {
        if(dist[i] == INT_MAX) {
            cout << -1;
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans;
}
