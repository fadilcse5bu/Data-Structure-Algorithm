#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1000000007;
ll fact[200005];

ll BigMod(ll b, ll p) {
	if(p == 0) return 1;
	if(p & 1) return (b * BigMod(b, p - 1)) % mod;
	else {
		ll temp = BigMod(b, p / 2);
		return (temp * temp) % mod;
	}
}

ll ncr(ll n, ll r) {
	if(n < r) return 0;
	if(r == 0) return 1;
	ll v1 = BigMod(fact[r], mod - 2);
	ll v2 = BigMod(fact[n - r], mod - 2);
	return (((v1 * v2) % mod) * fact[n]) % mod;
}

int main()
{
	fact[0] = 1;
	for(ll i = 1; i <= 200001; i++) fact[i] = (fact[i -1] * i) % mod;
	cout << ncr(7, 3);
	
	return 0;
}

