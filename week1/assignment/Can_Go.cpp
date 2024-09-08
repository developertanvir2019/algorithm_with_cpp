#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && (graph[x][y] == '.' || graph[x][y] == 'A' || graph[x][y] == 'B');
}

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (valid(nx, ny) && !vis[nx][ny]) {
            vis[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;

    pair<int, int> start;
    pair<int, int> end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'A') {
                start = {i, j};
            } else if (graph[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    memset(vis, false, sizeof(vis));

    dfs(start.first, start.second);

    if (vis[end.first][end.second]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
