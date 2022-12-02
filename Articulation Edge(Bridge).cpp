#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector <int> edges[10005];
vector <pair<int, int>> bridge;
int cur_time, low[10005], disc[10005], par[10005];
bool vis[10005];

void dfs(int x, int p) {
  par[x] = p;
  vis[x] = 1;
  low[x] = disc[x] = ++cur_time;
  for(int i = 0; i < edges[x].size(); i++) {
    if(!vis[edges[x][i]]) {
      dfs(edges[x][i], x);
      low[x] = min(low[x], low[edges[x][i]]);

      if(low[edges[x][i]] > disc[x]) {
        if(edges[x][i] > x) {
          bridge.push_back({x, edges[x][i]});
        }
        else {
          bridge.push_back({edges[x][i], x});
        }
      }
    }
    else if(edges[x][i] != par[x]) {
      low[x] = min(low[x], disc[edges[x][i]]);
    }
  }
}

int main()
{
  int t = 1, cs = 1;
  //cin >> t;
  while(t--) {
    int n, e;
    cin >> n >> e;  //total nodes & edges
    bridge.clear();
    for(int i = 0; i <= n; i++) {
      vis[i] = 0;
      edges[i].clear();
    }

    for(int i = 0; i < e; i++) {
      int u, v;
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
      if(vis[i] == 0) {
        dfs(i, -1);
      }
    }

    sort(bridge.begin(), bridge.end());
    for(int i = 0; i < bridge.size(); i++) {
      cout << bridge[i].first << " - " << bridge[i].second << endl;
    }
  }


	return 0;
}


