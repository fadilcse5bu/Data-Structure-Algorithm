#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll josephus(ll n, ll k) {
    if (n == 1)
        return 0;
    if (k > n)
        return (josephus(n-1, k) + k) % n;
    ll res = josephus(n - (n / k), k);
    if (res < n % k)
        res = res - n % k + n;
    else
        res = (k * (res - n % k) / (k - 1));
    return res;
}

int main()
{
  ll n, k;
  while(cin >> n) {
    cin >> k;
    cout << josephus(n, k) + 1 << endl;
  }

	return 0;
}

