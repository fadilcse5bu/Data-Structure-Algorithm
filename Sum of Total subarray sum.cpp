#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    ll ans = 0, v;
    for(ll i = 0; i < n; i++){
        v = (i + 1) * (n - i) * a[i];
        v %= 1000000007;
        ans += v;
        ans %= 1000000007;
    }

    cout << ans << endl;

    return 0;
}
