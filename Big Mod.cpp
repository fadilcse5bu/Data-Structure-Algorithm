#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 7;

ll  BigMod(ll a, ll p)
{
    if(p == 0)
        return 1;
    if(p % 2 != 0)
        return (a * BigMod(a, p - 1)) % mod;
    else{
        ll tmp = BigMod(a, p / 2) % mod;
        return (tmp * tmp) % mod;
    }
}

int main()
{
    ll aa,pp;
    cin>>aa>>pp;
    cout<<BigMod(aa,pp);

    return 0;
}
