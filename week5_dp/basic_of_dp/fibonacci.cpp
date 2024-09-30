#include <bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int dp[N];
int fibonacci(int n){
    if(n==0 ||n==1)return n;

    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=fibonacci(n-1)+fibonacci(n-2);
    dp[n]=ans;
    return ans;
}
int main (){
    
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
   int ans= fibonacci(n);
   cout<<ans;
    return 0;
}