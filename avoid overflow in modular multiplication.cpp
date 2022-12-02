#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e12;

ll mulMod(ll a, ll b, ll mod)
{
  ll res = 0;
  a = a % mod;
  while(b > 0) {
    if(b % 2 == 1) {
      res = (res + a) % mod;
    }
    a = (a * 2) % mod;
    b /= 2;
  }

  return res % mod;
}

ll bigMod(ll b, ll p, ll mod)
{
  if(p == 0) return 1;
  if(p % 2 == 1) {
    ll v = bigMod(b, p - 1, mod) % mod;
    ll res = mulMod(b, v, mod);
    return res;
  }
  else {
    ll temp = bigMod(b, p / 2, mod) % mod;
    ll res = mulMod(temp, temp, mod);
    return res;
  }
}

int main()
{
  ll b, p;
  cin >> b >> p;
  cout << bigMod(b, p, mod);


  return 0;
}
