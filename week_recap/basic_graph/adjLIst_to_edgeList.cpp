#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int u,v,w;
    Edge(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
void convert(int n, vector<pair<int,int>>adj[]){
    int mat[n][n];
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=-1;
            if(i==j) mat[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        for(pair<int,int> child:adj[i]){
          int childNode=child.first;
          int cost =child.second;
          mat[i][childNode]=cost;
        }
    }
}
int main (){
    int n,e;
    cin>>n>>e;

    // problem e adjacency list dewa thakbe ekhane baniye nilam;
    vector<pair<int,int>>v[n];
    while(e--){
        int a,b,c;
        cin>>a>>b,c;
        v[a].push_back({b,c});
    }
    vector<Edge> edgeList;
    for(int i=0;i<n;i++){
        for(pair<int,int> child:v[i]){
            int childNode=child.first;
            int cost=child.second;
            edgeList.push_back(Edge(i,childNode,cost));
        }
    }

    return 0;
}