#include <bits/stdc++.h>
using namespace std;
bool vis[100][100]; 
int dis[100][100];  
vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int n, m;
bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int bfs(int ki, int kj, int qi, int qj) {
    queue<pair<int, int>> q;
    q.push({ki, kj});
    vis[ki][kj] = true;
    dis[ki][kj] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); 
        q.pop();

        if (x == qi && y == qj) return dis[x][y];
        for (auto [dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (valid(nx, ny) && !vis[nx][ny]) {
                vis[nx][ny] = true;
                dis[nx][ny] = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        int ki, kj;
        cin >> ki >> kj;

        int qi, qj;
        cin >> qi >> qj;
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        if (ki == qi && kj == qj) {
            cout << 0 << endl;
        } else {
            cout << bfs(ki, kj, qi, qj) << endl;
        }
    }

    return 0;
}
