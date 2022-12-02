#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dist[501][501];
ll inf = 1e18;

void floydWarshall(int n) {
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(dist[i][k] == inf || dist[k][j] == inf) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

void checkNegativeCycle(int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; dist[i][j] != -inf && k < n; k++) {
        if(dist[k][k] < 0 && dist[i][k] != inf && dist[k][j] != inf) {
          dist[i][j] = -inf;
        }
      }
    }
  }
}

int main()
{
  while(1) {
    int n, m, q;
    cin >> n >> m >> q;
    if(n == 0) return 0;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        dist[i][j] = inf;
        if(i == j) dist[i][j] = 0;
      }
    }

    for(int i = 0; i < m; i++) {
      ll u, v, w;
      cin >> u >> v >> w;
      dist[u][v] = min(w, dist[u][v]);
    }

    floydWarshall(n);
    checkNegativeCycle(n);

    while(q--) {
      int u, v;
      cin >> u >> v;
      if(dist[u][v] == inf) cout << "Impossible" << endl;
      else if(dist[u][v] == -inf) cout << "-Infinity" << endl;
      else cout << dist[u][v] << endl;
    }
  }

  return 0;
}
/*
4 3 4
0 1 2
1 2 2
3 3 1
0 2
1 2
3 0
3 3
2 1 2
0 1 100
0 1
1 0
0 0 0
*/

