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
    vector<int>v[n];

     for(int i=0;i<n;i++){
        for(int j=0;i<n;j++){
           if(mat[i][j]==1){
            v[i].push_back(j);
           }
        }
    }
    return 0;
}