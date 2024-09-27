#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N];
vector<int>adj[N];
int parArray[N];
bool ans;
void dfs(int parent){
    vis[parent]=true;
    for(int child:adj[parent]){

        if(vis[child] &&child!=parArray[parent]){ 
        ans =true;
        }
        if(!vis[child]){
            parArray[child]=parent;
            dfs(child);
        }
    } 
}
int main (){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parArray,-1,sizeof(parArray));
    ans=false;

    for(int i=0;i<n;i++){
       if(!vis[i]){
        dfs(i);
       }
    }

    if(ans){
        cout<<"Cycle found";
    }else cout<<"Cycle Not found";
    return 0;
} 