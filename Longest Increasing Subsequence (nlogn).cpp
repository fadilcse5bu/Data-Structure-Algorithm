///Bismillah

#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector <int> v, v1, v2;
	vector <int> :: iterator I;
	int n;
	cin >> n;
	int ar[n + 1];
	for(int i = 0, a; i < n; i++){
		cin >> a;
		v.push_back(a);
	}
	int l = v.size() - 1, c = l;
	v1.push_back(v[0]);
	
	for(int i = 1; i < n; i++){
		if(v1.size() > v2.size()){
			v2.clear();
			v2.assign(v1.begin(), v1.end());
		}
		if(v[i] > v1[v1.size() - 1]){
			v1.push_back(v[i]);
		}
		else{
			I = lower_bound(v1.begin(), v1.end(), v[i]);
			c = (I - v1.begin());
			v1[c] = v[i];
		}
		
	}
	
	if(v1.size() > v2.size()){
		v2.clear();
		v2.assign(v1.begin(), v1.end());
	}
	
	cout << v2.size() << endl;
	//for(auto i : v2) cout << i << ' ';
	return 0;
}

///Alhumdulillah
