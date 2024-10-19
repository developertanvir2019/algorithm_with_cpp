#include<bits/stdc++.h>
#define ll long long
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main()
{
    fast();
    int n;
    cin >> n;
    int vec[n];
    ll sum = 0;
    for (int i=0;i<n;i++) {
        cin >> vec[i];
        sum += vec[i];
    }
    int idx = -1;
    ll sum1 = 0;
   for(int i=0;i<n;i++){
    sum1+=vec[i];
    if(sum1==sum-sum1+vec[i]){
        idx=i;
        break;
    }
   }
    if (idx == -1) {
        cout << "UNSTABLE" << endl;
        return 0;
    }
    cout << sum1 << " " << idx + 1 << endl;
    return 0;
}