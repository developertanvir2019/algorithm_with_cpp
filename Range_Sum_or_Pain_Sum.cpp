#include<bits/stdc++.h>
#define ll long long
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

ll val(ll n) {
    return (n * (n + 1)) / 2;
}


int main()
{
    fast();
     int n, q;
    cin >> n >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        int bad = 0, l_bad = 0;
        if (r % 2) {
            bad = ceil(r / 2.00);
        }
        if (l % 2 == 0) {
            l_bad = ceil(l / 2.00);
        }
        r = ceil(r / 2.00);
        l = ceil(l / 2.00);
        ll ans = val(r) - val(l - 1);
        cout << 2 * ans - bad - l_bad  << endl;
    }
    return 0;
}