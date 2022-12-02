#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct info {
	ll prop, sum;
} tree[300005];

void update(int node, int b, int e, int up_left, int up_right, ll x)
{
	if(up_left > e or up_right < b)
		return;
	if(b >= up_left and e <= up_right)
	{
		tree[node].sum += ((e - b + 1) * x);
		tree[node].prop += x;
		return;
	}
	
	int Left = node * 2;
	int Right = (node * 2) + 1;
	int mid = (b + e) / 2;
	update(Left, b, mid, up_left, up_right, x);
	update(Right, mid + 1, e, up_left , up_right, x);
	tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

ll query(int node, int b, int e, int up_left, int up_right, ll carry = 0)
{
	if(up_left > e or up_right < b) return 0;
	if(b >= up_left and e <= up_right) {
		return tree[node].sum + carry * (e - b + 1);
	}
	int Left = node << 1;
	int Right = (node << 1) + 1;
	int mid = (b + e) >> 1;
	
	ll p1 = query(Left, b, mid, up_left, up_right, carry + tree[node].prop);
	ll p2 = query(Right, mid + 1, e, up_left, up_right, carry + tree[node].prop);
	
	return p1 + p2;
}

int main()
{
	update(1, 1, 8, 2, 6, 5);
	cout << query(1, 1, 8, 4, 6) << endl;
	
	return 0;
}
