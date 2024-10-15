#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read number of test cases
    while (t--) {
        int n;
        cin >> n;  // Read number of coins
        vector<int> arr(n);
        int totalSum = 0;

        // Read the coin values and calculate total sum
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            totalSum += arr[i];
        }

        int target = totalSum / 2;  // Target is half of total sum
        vector<bool> dp(target + 1, false);
        dp[0] = true;  // A sum of 0 is always achievable

        // Dynamic programming to find the closest sum <= totalSum / 2
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= arr[i]; j--) {
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }

        // Find the largest sum closest to totalSum / 2
        int maxSumPossible = 0;  // Initialize maximum sum achievable
        for (int i = target; i >= 0; i--) {
            if (dp[i]) {
                maxSumPossible = i;  // Update the maximum achievable sum
                break;  // Exit loop once found
            }
        }

        // Calculate minimum difference
        int minDifference = totalSum - 2 * maxSumPossible;  // Return the minimum difference
        cout << minDifference << endl;  // Output the result
    }
    return 0;
}
