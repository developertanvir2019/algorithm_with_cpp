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
        int n;
        cin >> n;
        int a[n], sum = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        
        if (sum % 2 != 0) {  
            cout << "NO" << endl;
            continue;
        }

        int target = sum / 2;
        memset(dp, -1, sizeof(dp)); 
        
        if (checkSum(n, target, a)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
