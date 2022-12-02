#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dis[100005], par[100005], inf = 1e18, n, m;
vector <pair<ll, ll>> G[100005];

void Dijkstra(ll src) {
  dis[src] = 0;
  priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, src});

  while(!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    ll v = p.second;
    for(int i = 0; i < G[v].size(); i++) {
      if(dis[v] + G[v][i].second < dis[G[v][i].first]) {
        dis[G[v][i].first] = dis[v] + G[v][i].second;
        par[G[v][i].first] = p.second;
        pq.push({dis[G[v][i].first], G[v][i].first});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t = 1, cs = 1;
  //cin >> t;
  while(t--) {
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
      dis[i] = inf;
      G[i].clear();
    }

    for(int i = 0; i < m; i++) {
      ll u, v, w;
      cin >> u >> v >> w;
      G[u].push_back({v, w});
      G[v].push_back({u, w});
    }

    Dijkstra(1);

    //path finding
    vector <int> path;
    int nd = n, ck = 0;
    path.push_back(n);
    while(1) {
      if(par[nd] == 1) ck = 1;
      if(par[nd] == 0) {
        break;
      }
      nd = par[nd];
      path.push_back(nd);
    }

    cout << path.size() << endl;
    for(int i = path.size() - 1; i >= 0; i--) {
      cout << path[i] << ' ';
    }
    cout << endl;
  }

  return 0;
}




