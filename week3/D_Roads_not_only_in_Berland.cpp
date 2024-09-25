#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int parent [N],group_size[N];

void dsu_initialize(int n){
    for(int i=1;i<=n;i++){ 
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node){
    if(parent[node]==-1)return node;
    return parent[node]=dsu_find(parent[node]);
}

void dsu_union_by_size(int node1,int node2){
    int leaderA=dsu_find(node1);
    int leaderB=dsu_find(node2);
    if(leaderA !=leaderB){
        if(group_size[leaderA]>group_size[leaderB]){
            parent[leaderA]=leaderB;
            group_size[leaderB] +=group_size[leaderA];
        }else {
            parent[leaderA]=leaderB;
            group_size[leaderB]+=group_size[leaderA];
    
        }
    }
}

int main(){
    int n;cin>>n;
    dsu_initialize(n);
    vector<pair<int,int>>redundant_roads;
    vector <pair<int,int>> roads;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        if(dsu_find(u)==dsu_find(v)){
            redundant_roads.push_back({u,v});
        }else{
            dsu_union_by_size(u,v);
        }
    }
    vector<int> leaders;
    for (int i = 1; i <= n; i++) {  // loop from 1 to n
    if (dsu_find(i) == i) {
        leaders.push_back(i);
    }
}

    int t = redundant_roads.size();
    cout << t << endl;

    for (int i = 0; i < t; i++) {
        cout << redundant_roads[i].first << " " << redundant_roads[i].second << " " 
             << leaders[i] << " " << leaders[i + 1] << endl;
        dsu_union_by_size(leaders[i], leaders[i + 1]);
    }

    return 0;
}