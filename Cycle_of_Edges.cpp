#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> arr[N];
bool vis[N];
int parent_arr[N];

int ans=0;
void dfs(int parent){
    vis[parent]=true;
     for(int child:arr[parent]){
        if(vis[child] &&child!=parent_arr[parent]){ 
        ans ++;
        }
        if(!vis[child]){
             parent_arr[child]=parent;
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
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parent_arr,-1,sizeof(parent_arr));

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout<<ans/2<<endl;
    return 0;
}