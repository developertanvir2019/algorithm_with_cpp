#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;  
    while (t--) {
        int n;
        cin >> n;  
        int h[n];
        for (int i = 0; i < n; i++) {
            cin >> h[i];  
        }

        int max1 = -1, max2 = -1;  
        int index1 = -1, index2 = -1;  

        for (int i = 0; i < n; i++) {
            if (h[i] > max1) {
                max2 = max1;  
                index2 = index1;  
                max1 = h[i];  
                index1 = i;  
            } else if (h[i] > max2) {
                max2 = h[i];  
                index2 = i;  
            }
        }
        if (index1 > index2) {
            swap(index1, index2);
        }
        cout << index1 << " " << index2 << endl;
    }
    return 0;
}
