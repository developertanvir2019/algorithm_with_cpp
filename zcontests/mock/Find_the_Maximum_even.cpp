#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    int max_even = -1; 
    for (int i = 0; i < n; i++) {
        if (val[i] % 2 == 0) {
            max_even = max(max_even, val[i]);
        }
        for (int j = i + 1; j < n; j++) {
            if ((val[i] + val[j]) % 2 == 0) {
                max_even = max(max_even, val[i] + val[j]);
            }
        }
    }

    cout << max_even << endl;
    return 0;
}
