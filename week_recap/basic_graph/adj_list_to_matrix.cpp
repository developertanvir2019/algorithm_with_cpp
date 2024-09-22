#include <bits/stdc++.h>
using namespace std;



void convert(int n, vector<int>adj[]){
    int mat[n][n];
    memset(mat,0,sizeof(mat));
    for(int i=0;i<n;i++){
        for(int child:adj[i]){
            mat[i][child]=1;
        }
    }
}
int main (){
    int n,e;
    cin>>n>>e;

    // problem e adjacency list dewa thakbe ekhane baniye nilam;
    vector<int>v[n];
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    convert(n,v);
    return 0;
}