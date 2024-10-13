#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;   
    vector<int> a(n + 1);  
    vector<int> distinct_count(n + 1);   
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }    
    set<int> seen; 
    for (int i = n; i >= 1; --i) {
        seen.insert(a[i]);  
        distinct_count[i] = seen.size();
    }
    for (int i = 0; i < m; ++i) {
        int l;
        cin >> l;
        cout << distinct_count[l] << endl;
    }
    
    return 0;
}