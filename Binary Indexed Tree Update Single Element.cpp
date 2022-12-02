#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int ar[500000], tree[500000];

void update_tree(int idx, int val, int n)
{
    while(idx <= n) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

ll sumOfRange(int l, int r)
{
    ll a = 0, b = 0;
    while(r > 0) {
        b += tree[r];
        r -= (r & -r);
    }
    while(l > 0) {
        a += tree[l];
        l -= (l & -l);
    }

    return b - a;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ar[i];
        update_tree(i, ar[i], n);
    }


    int query;
    cin >> query;
    while(query--) {
        int query_type;
        cin >> query_type;
        if(query_type == 1) {
            int indx, val;
            cin >> indx >> val;
            update_tree(indx, val, n);
        }
        else if(query_type == 2) {
            int left_indx, right_indx;
            cin >> left_indx >> right_indx;
            ll ans = sumOfRange(left_indx - 1, right_indx);
            cout << ans << endl;
        }
    }

    return 0;
}
