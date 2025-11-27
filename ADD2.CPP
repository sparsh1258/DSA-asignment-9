#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int m = 3, n = 3;

    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0]=grid[0][0];

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;

    pq.push({dist[0][0], {0,0}});

    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    while(!pq.empty()) {
        auto p=pq.top(); pq.pop();
        int cost=p.first;
        int x=p.second.first;
        int y=p.second.second;

        if(cost>dist[x][y]) continue;

        for(auto &k:d) {
            int nx=x+k[0], ny=y+k[1];
            if(nx>=0 && ny>=0 && nx<m && ny<n) {
                int nc=cost+grid[nx][ny];
                if(nc<dist[nx][ny]) {
                    dist[nx][ny]=nc;
                    pq.push({nc,{nx,ny}});
                }
            }
        }
    }

    cout << dist[m-1][n-1];
}
