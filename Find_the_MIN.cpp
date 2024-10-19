#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> count;
    set<int> activeValues;
    int currentMin = INT_MAX;

    while (n--) {
        int type, x;
        cin >> type;

        if (type == 1) {
            cin >> x;
            count[x]++;
            activeValues.insert(x);
            if (x < currentMin) {
                currentMin = x;
            }
        } else if (type == 2) {
            while (!activeValues.empty() && count[currentMin] == 0) {
                activeValues.erase(currentMin);
                currentMin = (activeValues.empty() ? INT_MAX : *activeValues.begin());
            }

            if (currentMin == INT_MAX) {
                cout << "empty\n";
            } else {
                cout << currentMin << "\n";
                count[currentMin] = 0;
                activeValues.erase(currentMin);
                currentMin = (activeValues.empty() ? INT_MAX : *activeValues.begin());
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
