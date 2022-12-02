#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int ar[100005];
int tree[300100];

void inint(int node, int b, int e)
{
	if(b == e) {
		tree[node] = ar[b];
		return;
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	inint(left, b, mid);
	inint(right, mid + 1, e);
	tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j) 
{
	if(i > e or j < b) 
		return 0;
	if(b >= i and e <= j) 
		return tree[node];
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	int p1 = query(left, b, mid, i, j);
	int p2 = query(right, mid + 1, e, i, j);
	return p1 + p2;
}

void update(int node, int b, int e, int i, int newvalue)
{
	if(i > e or i < b)
		return;
	if(b >= i and e <= i) {
		tree[node] = newvalue;
		return;
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	update(left, b, mid, i, newvalue);
	update(right, mid + 1, e, i, newvalue);
	tree[node] = tree[left] + tree[right];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> ar[i];
    inint(1, 1, n);
    
    //for(int i = 1; i <= n; i++) cout << tree[i] << ' ';
    cout << query(1, 1, n, 3, 6) << endl; 
    update(1, 1, n, 5, -4);
    cout << query(1, 1, n, 3, 6) << endl;
    
    return 0;
}

