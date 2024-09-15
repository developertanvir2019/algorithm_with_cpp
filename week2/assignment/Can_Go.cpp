#include <bits/stdc++.h>
using namespace std;

const int N = 1005; 
vector<pair<int, int>> adj[N];  
int dis[N];  

class cmp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;  
    }
};

void dijkstra(int src, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});  
    dis[src] = 0;  

    while (!pq.empty()) {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;

        
        for (pair<int, int> child : adj[node]) {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode]) {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        dis[i] = INT_MAX;
    }

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    int s;
    cin >> s;
    dijkstra(s, n);
    int t;
    cin >> t;
    while (t--) {
        int d, dw;
        cin >> d >> dw;
       if (dis[d] != INT_MAX && dis[d] <= dw) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
