#include <bits/stdc++.h>
using namespace std;

int graph[501][501];  // The matrix representing heights
int n;  // Matrix size

bool valid(int x, int y) {
    // Check if the coordinates are valid within the matrix boundaries
    return x >= 0 && x < n && y >= 0 && y < n;
}

int dfs(int si, int sj) {
    int operations = 0;
    stack<pair<int, int>> s;
    s.push({si, sj});
    
    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();
        
        if (graph[x][y] < 0) {  // If there's a lake (negative height), we need to perform magic
            operations++;
            int i = x, j = y;
            
            // Process the diagonal starting from (i, j)
            while (valid(i, j)) {
                graph[i][j] += 1;  // Increment the diagonal element by 1
                i++;
                j++;
            }
        }
    }
    return operations;
}

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        cin >> n;  // Read the size of the matrix for this test case

        // Read the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        int total_operations = 0;

        // Traverse the matrix diagonals
        for (int diag = 0; diag < n; diag++) {
            // Process diagonals starting from each main diagonal element
            total_operations += dfs(diag, diag);
        }

        cout << total_operations << endl;  // Output the result for this test case
    }

    return 0;
}
