#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    fast();
    int t;
    cin >> t;  
    while (t--) {
        int n;
        string s;
        cin >> n >> s; 
         int count = 0;
        for (int i = 0; i < s.length() - 1; i++) {
        if ((s[i] == '0' && s[i + 1] == '1') || (s[i] == '1' && s[i + 1] == '0')) {
            count++;
        }
    }
        cout <<count << endl; 
    }
    return 0;
}
