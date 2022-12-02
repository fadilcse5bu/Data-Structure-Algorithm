#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <int> ve[1000005];
int indeg[1000005];

// lexicographically order

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  start:
  while(t--) {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
      ve[i].clear();
      indeg[i] = 0;
    }

    for(int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      ve[b].push_back(a);
      indeg[a]++;
    }
    for(int i = 1; i <= n; i++) {
      sort(ve[i].begin(), ve[i].end());
    }

    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i = 1; i <= n; i++) {
      if(indeg[i] == 0) {
        pq.push(i);
      }
    }

    vector <int> ans;
    while(!pq.empty()) {
      int x = pq.top();
      pq.pop();
      ans.push_back(x);
      for(int i = 0; i < ve[x].size(); i++) {
        --indeg[ve[x][i]];
        if(indeg[ve[x][i]] == 0) pq.push(ve[x][i]);
      }
    }

    if(ans.size() != n) {
      cout << -1 << endl;
      goto start;
    }

    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
  }

  return 0;
}
