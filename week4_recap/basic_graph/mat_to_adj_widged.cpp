#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;i<n;j++){
            cin>>mat[i][j];
        }
    }
    vector<pair<int,int>>v[n];

     for(int i=0;i<n;i++){
        for(int j=0;i<n;j++){
           if(mat[i][j]>0 &&i!=j){
            v[i].push_back({j,mat[i][j]});
           }
        }
    }
    return 0;
}