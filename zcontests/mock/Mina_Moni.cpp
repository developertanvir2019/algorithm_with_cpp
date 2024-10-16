#include<bits/stdc++.h>
#define ll long long
#define B begin()
#define E end()
#define all(x) x.B,x.E
using namespace std;
int n;
vector<int> vec;
int sum, half;

int dp[15][15007][10];

int f(int i, int crrSum, int coin) {

    if (i == n ) {
        if (coin == half) return abs((sum - crrSum) - crrSum);
        else return INT_MAX;
    }

    // if (i >= n or coin > half) return INT_MAX;

    if (dp[i][crrSum][coin] != -1) return dp[i][crrSum][coin];
    return dp[i][crrSum][coin] = min(f(i + 1, crrSum + vec[i], coin + 1),
                                     f(i + 1, crrSum, coin));
}

void solve() {
    cin >> n;
    sum = 0;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        sum += vec[i];
    }

    if (n == 1) {
        cout << vec[0] << endl;
        return;
    }

    half = (n / 2);
    if (n % 2) half++;

    memset(dp, -1, sizeof(dp));
    cout << f(0, 0, 0) << endl;
}


int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}