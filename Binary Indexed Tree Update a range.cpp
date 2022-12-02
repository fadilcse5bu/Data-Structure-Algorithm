#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mul[100005], add[100005], n;
void internalUpdate(ll indx, ll ml, ll ad)
{
    while(indx <= n) {
        mul[indx] += ml;
        add[indx] += ad;
        indx += (indx & -indx);
    }
}

void update(ll left, ll right, ll val)
{
    internalUpdate(left, val, -val * (left - 1));
    internalUpdate(right + 1, -val, val * right);
}

ll sumOfRange(ll indx)
{
    ll ml = 0, ad = 0, start = indx;
    while(indx > 0) {
        ml += mul[indx];
        ad += add[indx];
        indx -= (indx & -indx);
    }

    return ml * start + ad;
}

int main()
{
    int q;
    cin >> n >> q;
    ll ar[n + 1];
    for(ll i = 1; i <= n; i++) {
        cin >> ar[i];
        update(i, i, ar[i]);
    }

    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            ll i, j, val;
            cin >> i >> j >> val;
            update(i, j, val);
        }
        else {
            ll i, j;
            cin >> i >> j;
            cout << sumOfRange(j) - sumOfRange(i - 1) << endl;
        }
    }

    return 0;
}
