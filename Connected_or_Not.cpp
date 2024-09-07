 #include <bits/stdc++.h>
 using namespace std;
 
 int main (){
     int n,e;
     cin>>n>>e;
     vector<int> list[n];
     while(e--){
        int a,b;
        cin>>a>>b;
        list[a].push_back(b);
     }
     int q;
     cin>>q;
     while(q--){
        int a,b;
        cin>>a>>b;
        bool found=false;

         for (int i = 0; i < list[a].size(); i++) {
            if (list[a][i] == b) {
                found = true;
            }}
        if(found){
            cout<<"YES"<<endl;          
        }else if(a==b){
                cout<<"YES"<<endl;
            }else{
            cout<<"NO"<<endl;
        }

     }

     return 0;
 }