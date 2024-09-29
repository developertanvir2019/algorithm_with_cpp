#include <bits/stdc++.h>
using namespace std;


const int N=1e5+5;
int parent[N];
int group_sz[N];

 class Edge{
    public:
    int a,b,w;
    Edge(int a,int b,int w){
        this->a=a;
        this->b=b;
        this->w=w;
    }
 };
void dsu_initialize(int n){
    for(int i=0;i<n;i++){
         parent[i]=-1;
        group_sz[i]=1;
    }
}

int dsu_find(int node){
    if(parent[node]==-1) return node;
    int leader= dsu_find(parent[node]);
    parent[node]=leader;
    return leader;
}

void dsu_union_by_size(int node1,int node2){
    int leaderA=dsu_find(node1);
    int leaderB=dsu_find(node2);
    if(group_sz[leaderA]>group_sz[leaderB]){
        parent[leaderB]=leaderA;
        group_sz[leaderA] +=group_sz[leaderB];
    }else{
         parent[leaderA]=leaderB;
        group_sz[leaderB] +=group_sz[leaderA];
    }
}

 bool cmp(Edge a,Edge b){
    return a.w<b.w;
 }
int main (){
    int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    vector<Edge> edgeList;
    for(int i=0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edgeList.push_back(Edge(a,b,w));
    }
     sort(edgeList.begin(), edgeList.end(), cmp);

     long long int cost = 0;

    int edge_need = 0;

    for (Edge ed : edgeList)
    {
        int leaderA = dsu_find(ed.a);
        int leaderB = dsu_find(ed.b);

        if (leaderA != leaderB)
        {
            dsu_union_by_size(ed.a, ed.b);
            cost += ed.w;
            edge_need++;
        }
    }

    int first_nodes_leader = dsu_find(0);

    bool connected_everyone = true;

    for (int i = 1; i < n; i++)
    {
        if (dsu_find(i) != first_nodes_leader)
        {
            connected_everyone = false;
        }
    }

    if (connected_everyone)
        cout <<e-edge_need<<" "<< cost << endl;
    else
        cout << "Not Possible" << endl;
    
    return 0;
}