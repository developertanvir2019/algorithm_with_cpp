#include<bits/stdc++.h>
#define ll long long
#define B begin()
#define E end()
#define all(x) x.B,x.E
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;


class cmp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};


void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    while (n--) {
        int x, y;
        cin >> x;
        if (x == 1) {
            cin >> y;
            mp[y]++;
            pq.push({mp[y], y});
        }
        else {
            if (pq.empty()) {
                cout << "empty" << "\n";
            }
            else {
                while (!pq.empty()) {
                    auto it = pq.top();
                    int frq = it.first;
                    int crr = it.second;
                    // cout << frq << " " << crr << "\n";
                    if (mp[crr] == frq) {
                        cout << crr << "\n";
                        mp[crr] -= max(1, frq - 1);
                        pq.pop();
                        if (mp[crr] > 1) {
                            pq.push({mp[crr], crr});
                        }
                        break;
                    }
                    pq.pop();
                }
            }
        }
    }
}
int main()
{
    fast();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}