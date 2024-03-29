#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9+7;
ll f[2][2], base[2][2] = {{1, 1}, {1, 0}};

void matrix_exponent(ll n) {
  if(n <= 1) return;
  if(n%2 == 1) {
    matrix_exponent(n-1);
    ll v1 = (f[0][0]*base[0][0] + f[0][1]*base[1][0]) % mod;
    ll v2 = (f[0][0]*base[0][1] + f[0][1]*base[1][1]) % mod;
    ll v3 = (f[1][0]*base[0][0] + f[1][1]*base[1][0]) % mod;
    ll v4 = (f[1][0]*base[0][1] + f[1][1]*base[1][1]) % mod;
    f[0][0] = v1, f[0][1] = v2, f[1][0] = v3, f[1][1] = v4;
  }
  else {
    matrix_exponent(n / 2);
    ll v1 = (f[0][0]*f[0][0] + f[0][1]*f[1][0]) % mod;
    ll v2 = (f[0][0]*f[0][1] + f[0][1]*f[1][1]) % mod;
    ll v3 = (f[1][0]*f[0][0] + f[1][1]*f[1][0]) % mod;
    ll v4 = (f[1][0]*f[0][1] + f[1][1]*f[1][1]) % mod;
    f[0][0] = v1, f[0][1] = v2, f[1][0] = v3, f[1][1] = v4;
  }
}

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    ll first_fibo_num, second_fibo_num, nth_value;
    cin >> first_fibo_num >> second_fibo_num >> nth_value;

    // base equation is
    // f(n) = a*f(n-1) + b*f(n-2) + c*f(n-3) + ... + aa*f(0)

    f[0][0] = 1; // coefficient of f(n-1) = a
    f[0][1] = 1; // coefficient of f(n-2) = b
    f[1][0] = 1;
    f[1][1] = 0;

    ll fn;
    if(nth_value == 0) fn = first_fibo_num;
    else if(nth_value == 1) fn = second_fibo_num;
    else {
      matrix_exponent(nth_value-1);
      fn = (f[0][0]*second_fibo_num + f[0][1]*first_fibo_num) % mod;
    }

    cout << "Case " << cs++ << ": " << fn << endl;
  }
}

