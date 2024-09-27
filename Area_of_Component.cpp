 #include <bits/stdc++.h>
 using namespace std;
 char graph[1005][1005];
 bool vis[1005][1005];
 int n,m;


vector<pair<int,int>>d={{1,0},{-1,0},{0,1},{0,-1}};
bool valid(int i,int j){
    if(i>=0 &&i<n && j>=0 &&j<m) return true;
    else return false;
}

int dfs(int si, int sj) {
    vis[si][sj] = true;
    int count = 1; 

    for (int i = 0; i < 4; i++) {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] == '.') {
            int area = dfs(ci, cj); 
            count += area; 
        }
    }
    return count;
}


 int main (){
     cin>>n>>m;
     int minArea=INT_MAX;
     bool found=false;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
     }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(graph[i][j]=='.'&&!vis[i][j]){
           int area= dfs(i,j);
            minArea=min(minArea,area);
            found=true;
           }
        }
     }

     if(found) cout<<minArea<<endl;
     else cout<<-1<<endl;
     return 0;
 }