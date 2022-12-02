///Bismillah

#include<bits/stdc++.h>
using namespace std;

vector<int> x[1000];
long long int vis[1000],c=0;

void dfs(int u)
{
    vis[u]=1;
    c++;
    for(int i=0;i<x[u].size();i++){
        int v=x[u][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main()
{
    int n,k,i;
    cin>>n>>k;

    for(i=1;i<n;i++){
        int p,y,r;
        cin>>p>>y>>r;
        if(!r){
            x[p].push_back(y);
            x[y].push_back(p);
        }
    }

    //ll ans=bigmod(n,k);

    for(i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            //ans=(ans-bigmod(c,k)+mod)%mod;
            //c=0;
        }
    }

    cout<<c<<endl;
}
