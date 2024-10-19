#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int caseNum = 1; caseNum <= t; ++caseNum) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n, vector<int>(m));
        pair<int, int> start, end;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> graph[i][j];
                if (graph[i][j] == 0) start = {i, j};
                if (graph[i][j] == -1) end = {i, j};
            }
        }

        vector<vector<int>> dist(n, vector<int>(m, INF));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        dist[start.first][start.second] = 0;
        pq.push({0, start.first, start.second});

        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();

            if (make_pair(x, y) == end) {
                cout << "Case " << caseNum << ": " << d << "\n";
                break;
            }

            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && graph[nx][ny] != -2) {
                    int newDist = d + (graph[nx][ny] >= 0 ? graph[nx][ny] : 0);
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        pq.push({newDist, nx, ny});
                    }
                }
            }
        }

        if (dist[end.first][end.second] == INF) {
            cout << "Case " << caseNum << ": Impossible\n";
        }
    }

    return 0;
}
