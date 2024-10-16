#include <bits/stdc++.h>
using namespace std;

int main (){
       int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int ans = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= a[i + 1])
            a[i] = a[i + 1] - 1;

        if (a[i] < 0)
            a[i] = 0;

        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}