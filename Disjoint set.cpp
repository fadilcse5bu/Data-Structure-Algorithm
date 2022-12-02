#include<bits/stdc++.h>
using namespace std;

int p[100005];
void makeSet() {
	for(int i = 1; i <= 100000; i++) p[i] = i;
}

int find_parent(int a) {
	if(p[a] == a) return a;
	return p[a] = find_parent(p[a]);
}

int main()
{
	makeSet();
	
	int n;
	cin >> n;
	while(n--) {
		int u, v;
		cin >> u >> v;
		int x = find_parent(u);
		int y = find_parent(v);
		p[x] = y;
	}

	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		int x = find_parent(u);
		int y = find_parent(v);
		if(x == y) cout << "Friend" << endl;
		else cout << "Not friend" << endl;
	}

    return 0;
}

