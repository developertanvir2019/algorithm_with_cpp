 #include <bits/stdc++.h>
 using namespace std;
 const int N=1e5+5;
 int parent[N];
 int group_sz[N];
 void dsu_initialize(int n){
    for(int i=1;i<=n;i++){
        parent[i]=-1;
        group_sz[i]=1;
    }
 }

 int dsu_find(int node){
    if(parent[node]==-1)return node;
    int leader=dsu_find(parent[node]);
    parent[node]=leader;
    return leader;
 }

 void dsu_union_by_sz(int node1,int node2){
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
 class Edge{
    public:
    int a,b,w;
    Edge(int a,int b,int w){
        this->a=a;
        this->b=b;
        this->w=w;
    }
 };

 bool cmp(Edge a,Edge b){
    return a.w<b.w;
 }
 int main (){
    int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    vector<Edge> edgeList;
    while(e--){
        int a,b,w;
        cin>>a>>b>>w;
        edgeList.push_back(Edge(a,b,w));
    }
    sort(edgeList.begin(),edgeList.end(),cmp);
   long long int cost=0;
    for(Edge ed:edgeList){
        int leaderA=dsu_find(ed.a);
        int leaderB=dsu_find(ed.b);
        if(leaderA==leaderB){
            continue;
        }else{
            dsu_union_by_sz(leaderA,leaderB);
            cost+=ed.w;
        }
    }
    bool flag = true;
    int leader = dsu_find(1);  
    for(int i = 2; i <= n; i++){ 
        if(dsu_find(i) != leader){ 
            flag = false;
            break;
        }
    }
    if(flag)cout<<cost<<endl;
    else cout<<-1<<endl;
     
     return 0;
 }