#include<bits/stdc++.h>
using namespace std;

int parent[100005];
void makeSet() {
	for(int i = 1; i <= 100000; i++) parent[i] = i;
}

int find(int a) {
	if(parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

int main()
{
	makeSet();
	
	int totalRelationships;
	cin >> totalRelationships;
	while(totalRelationships--) {
		int Person1, Person2;
		cin >> Person1 >> Person2;
		int u = find(Person1);
		int v = find(Person2);
		parent[u] = v;
	}

	int query;
	cin >> query;
	while(query--) {
		int person1, person2;
		cin >> person1 >> person2;
		int u = find(person1);
		int v = find(person2);
		if(u == v) cout << "Friend" << endl;
		else cout << "Not friend" << endl;
	}

    return 0;
}

