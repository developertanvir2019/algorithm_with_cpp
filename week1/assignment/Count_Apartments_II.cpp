#include <bits/stdc++.h>
using namespace std;
char graph[1001][1001];
bool vis[1001][1001];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; 

bool valid(int x, int y) {
     return x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.' && !vis[x][y];
}

int dfs(int si, int sj) {
    if (graph[si][sj] != '.') return 0;
    stack<pair<int, int>> s;
    s.push({si, sj});
    vis[si][sj] = true;
    int room_count = 0;

    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();
        room_count++;
        

        for (int i = 0; i < 4; i++) {
            int ci = x + dx[i];
            int cj = y + dy[i];

            if (valid(ci, cj)) {
                vis[ci][cj] = true;
                s.push({ci, cj});
            }
        }
    }
    return room_count;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> app_size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == '.' && !vis[i][j]) {
                int size = dfs(i, j);
                app_size.push_back(size);
            }
        }
    }
    if (app_size.empty()) {
        cout << "-1" << endl;
    } else {
        sort(app_size.begin(), app_size.end());
        for (int size : app_size) {
            cout << size << " ";
        }
        cout << endl;
    }

    return 0;
}
