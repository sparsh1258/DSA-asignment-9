#include <iostream>
#include <vector>
using namespace std;

int M = 3, N = 3;

void dfs(int x, int y, vector<vector<int>> &g, vector<vector<int>> &vis) {
    vis[x][y] = 1;
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for(auto &k: d) {
        int nx = x + k[0], ny = y + k[1];
        if(nx>=0 && ny>=0 && nx<M && ny<N && g[nx][ny]==1 && !vis[nx][ny])
            dfs(nx, ny, g, vis);
    }
}

int main() {
    vector<vector<int>> grid = {
        {1,1,0},
        {0,1,0},
        {1,0,1}
    };

    vector<vector<int>> vis(M, vector<int>(N,0));
    int count = 0;

    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            if(grid[i][j] == 1 && !vis[i][j]) {
                dfs(i, j, grid, vis);
                count++;
            }

    cout << count;
}
