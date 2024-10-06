#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool checkSum(int n, int sum, int arr[]) {
    if (sum == 0) return true;  
    if (n == 0 || sum < 0) return false;  
    
    if (dp[n][sum] != -1) return dp[n][sum];  
    
    if (arr[n-1] <= sum) {
        return dp[n][sum] = checkSum(n-1, sum-arr[n-1], arr) || checkSum(n-1, sum, arr);
    }
    
    return dp[n][sum] = checkSum(n-1, sum, arr);  
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (m == 1000) {
            cout << "YES" << endl;
            continue;
        }
        
        if (m > 1000) {
            cout << "NO" << endl;
            continue;
        }
        
        int target = 1000 - m; 
        memset(dp, -1, sizeof(dp)); 
        
        if (checkSum(n, target, a)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
