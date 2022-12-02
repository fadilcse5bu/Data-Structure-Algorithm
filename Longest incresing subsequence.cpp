///Bismillah

#include<bits/stdc++.h>
using namespace std;

vector <int> ve, ve1;

int main()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		ve.push_back(a);
		ve1.push_back(1);
	}
	
	int m = 0;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(ve[j] < ve[i]){
				ve1[i] = max(ve1[j] + 1, ve1[i]);
			}
			
			m = max(m, ve1[i]);
		}
	}
	
	cout << m;
	return 0;
	
}

///Alhumdulillah
