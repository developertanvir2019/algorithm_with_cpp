#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    fast();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x=0;
        int move=1;
        int Kosuke=true;
       for(int i=0;i<=n;i++){

        if(Kosuke){
            x-=move;
        }else{
            x+=move;
        }
        Kosuke=!Kosuke;
        move+=2;
       }
       if(Kosuke){
        cout<<"Kosuke\n";
       }else{
        cout<<"Sakurako\n";
       }
    }
    return 0;
}