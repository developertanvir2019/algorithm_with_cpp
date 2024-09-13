#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[1005][1005];
bool vis[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == '.' && !vis[x][y];
}

void dfs(int si, int sj) {
    vis[si][sj] = true; 

    for (int i = 0; i < 4; i++) {
        int ci = si + dx[i];
        int cj = sj + dy[i]; 

        if (valid(ci, cj)) {
            dfs(ci, cj); 
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j]; 
        }
    }

    int source_row, source_column;
    cin >> source_row >> source_column;
    int destination_row, destination_column;
    cin >> destination_row >> destination_column;

    dfs(source_row, source_column);

    if (vis[destination_row][destination_column]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
