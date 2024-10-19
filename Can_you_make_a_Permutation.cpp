

#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<bool> available(n + 1, false); 

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] >= 1 && a[i] <= n) {
                available[a[i]] = true;
            }
        }

        int cngNeed = 0;
        for (int i = 1; i <= n; ++i) {
            if (!available[i]) {
                cngNeed++; 
            }
        }

        if (cngNeed <= k) {
            cout << "YES"<<endl;
        } else {
            cout << "NO"<<endl;
        }
    }

    return 0;
}