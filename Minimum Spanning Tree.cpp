#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair <int, int> pd;

int main()
{
	int n, e;
	cin >> n >> e;
	vector <pair<int,int> > ve[n + 1];
	for(int i = 1; i <= e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ve[u].push_back({v, w});
		ve[v].push_back({u, w});
	}
	
	priority_queue <pd, vector<pd>, greater<pd> > pq;
	for(int i = 0; i < ve[1].size(); i++) {
		pq.push(make_pair(ve[1][i].second, ve[1][i].first));
	}

	int ans = 0;
	set <int> se;
	se.insert(1);
	while(!pq.empty()) {
		int u = pq.top().first, v = pq.top().second;
		pq.pop();
		if(se.count(v)) continue;
		se.insert(v);
		ans += u;
		for(int i = 0; i < ve[v].size(); i++) {
				pq.push({ve[v][i].second, ve[v][i].first});
		}
	}
	
	cout << endl << ans << endl;
	
		
	return 0;
}

