#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t;
   cin >> t;
   while (t--) {
      int n, k, ans = 0;
      cin >> n >> k;
      if (n % 2 == 0) {
         ans = k / 2;
      }
      else {
         ans = ceil(1.0 * k / 2);
      }
      cout << (ans % 2 == 0 ? "YES" : "NO") << '\n';
   }
   return 0;
}