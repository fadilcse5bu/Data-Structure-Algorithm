#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair <ll, ll> pr;

vector <pair<ll, ll>> edges[200005];
bool taken_node[200005];

int main()
{
  ll tc = 1; //test case
  //cin >> tc;
  while(tc--) {
    ll n, e; //number of node && number of edges
    cin >> n >> e;
    for(int i = 1; i <= n; i++) edges[i].clear();
    for(int i = 1; i <= e; i++) {
      ll u, v, w;
      cin >> u >> v >> w;
      edges[u].push_back({v, w});
      edges[v].push_back({u, w});
    }

    priority_queue <pr, vector<pr>, greater<pr>> pq; // increasing order
    for(int i = 0; i < edges[1].size(); i++) {
      pq.push({edges[1][i].second, edges[1][i].first});
    }

    ll min_cost = 0;
    memset(taken_node, false, sizeof taken_node);
    taken_node[1] = true;
    while(!pq.empty()) {
      ll u = pq.top().first, v = pq.top().second;
      pq.pop();
      if(taken_node[v] == true) continue;
      taken_node[v] = true;
      min_cost += u;
      for(int i = 0; i < edges[v].size(); i++) {
          pq.push({edges[v][i].second, edges[v][i].first});
      }
    }

    cout << min_cost << endl;
  }

	return 0;
}


