#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    
    vector<int> list[n];
    while (e--) {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    
    int q;
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        vector<int> connect;
        
        for (int node : list[a]) {
            connect.push_back(node);
        }
        
        if (connect.empty()) {
            cout << "-1" << endl;
        } else {
            sort(connect.begin(), connect.end(),greater<int>());
            
            for (int node : connect) {
                cout << node << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
