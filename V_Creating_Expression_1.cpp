#include <bits/stdc++.h>
using namespace std;

bool checkSum(int idx, long long currentSum, vector<int>& arr, long long X) {
    if (idx == arr.size()) {
        return currentSum == X;
    }

    // Explore both adding and subtracting the current element
    bool add = checkSum(idx + 1, currentSum + arr[idx], arr, X);
    bool subtract = checkSum(idx + 1, currentSum - arr[idx], arr, X);

    return add || subtract;
}

int main() {
    int N;
    long long X;
    cin >> N >> X;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Start the recursion
    if (checkSum(0, 0, arr, X)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
