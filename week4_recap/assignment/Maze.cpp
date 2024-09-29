#include <bits/stdc++.h>
using namespace std;

bool vis[1005][1005];
int dis[1005][1005];
pair<int, int> parent[1005][1005];
int n, m;
char a[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    return (i >= 0 && i<n && j>=0 && j<m && a[i][j] != '#' && !vis[i][j]);
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;

            if (valid(ci, cj)) {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;
                parent[ci][cj] = {par.first, par.second};

                if (a[ci][cj] == 'D') {
                    int x = ci, y = cj;
                    while (a[x][y] != 'R') {
                        if (a[x][y] != 'D') a[x][y] = 'X';
                        pair<int, int> p = parent[x][y];
                        x = p.first;
                        y = p.second;
                    }
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    int si, sj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'R') {
                si = i;
                sj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));

    bfs(si, sj);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}