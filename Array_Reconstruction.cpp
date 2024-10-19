#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        long long sum_ace = 0;
        for (int i = 0; i < n - 2; i++) {
            long long num;
            cin >> num;
            sum_ace += num;
        }
        
        long long total_sum; 
        cin >> total_sum;
        long long baki_sum = total_sum - sum_ace;
        if (baki_sum < 0) {
            cout << 0 << endl;
        } else {
            long long ways = baki_sum + 1;
            cout << ways << endl;
        }
    }
    
    return 0;
}
