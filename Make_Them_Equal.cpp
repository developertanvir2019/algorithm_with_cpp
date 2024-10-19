#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k; 
        cin >> n >> k;
        
        string s1, s2;
        cin >> s1 >> s2;
        
        int diffCnt = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diffCnt++;
            }
        }
        if (diffCnt <= k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
