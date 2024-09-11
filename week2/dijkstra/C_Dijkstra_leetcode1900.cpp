#include <bits/stdc++.h>
using namespace std;

const int N = 100005; 
vector<pair<int, int>> adj[N]; 
int dist[N], parent[N]; 
const int INF = 1e9 + 7; 

class cmp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second; 
    }
};

void dijkstra(int src, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dist[src] = 0;

    while (!pq.empty()) {
        pair<int, int> current = pq.top(); 
        pq.pop();
        int node = current.first;
        int cost = current.second;

        for (pair<int, int> neighbor : adj[node]) {
            int neighborNode = neighbor.first;
            int neighborCost = neighbor.second;

            if (cost + neighborCost < dist[neighborNode]) {
                dist[neighborNode] = cost + neighborCost;
                parent[neighborNode] = node; 
                pq.push({neighborNode, dist[neighborNode]});
            }
        }
    }
}

void printShortestPath(int n) {
    if (dist[n] == INF) {
        cout << -1 << endl; 
        return;
    }

    vector<int> path;
    for (int i = n; i != -1; i = parent[i]) {
        path.push_back(i);
    }

    reverse(path.begin(), path.end());

    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dijkstra(1, n);
    printShortestPath(n);

    return 0;
}
