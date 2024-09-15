#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, w;
    Edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

const int N = 1e5 + 5;
int dis[N];

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> EdgeList;
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        EdgeList.push_back(Edge(a, b, w));
    }
    for (int i = 1; i <= n; i++) { 
        dis[i] = INT_MAX;
    }

    int src;
    cin >> src;  
    dis[src] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (Edge ed : EdgeList) {
            int a = ed.a;
            int b = ed.b;
            int w = ed.w;
            if (dis[a] < INT_MAX && dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
            }
        }
    }
    
    bool cycle = false;
    for (Edge ed : EdgeList) {
        int a = ed.a;
        int b = ed.b;
        int w = ed.w;
        if (dis[a] < INT_MAX && dis[a] + w < dis[b]) {
            cycle = true;
            break;
        }
    }
    if (cycle) {
        cout << "Negative Cycle Detected" << endl;
        return 0;  
    }
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;  
        if (dis[d] < INT_MAX) {
            cout << dis[d] << endl;
        } else {
            cout << "Not Possible" << endl;
        }
    }

    return 0;
}
