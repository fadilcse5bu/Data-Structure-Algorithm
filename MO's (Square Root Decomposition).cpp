#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1e9+7;
const int maxn = 200002;
ll K, ans[maxn], a[maxn], sum = 0, cnt[1000005], n, t;

struct Query{
  int index, L, R;
  bool operator < (const Query &other) {
    int block_own = L/K;
    int block_other = other.L/K;
    if(block_own == block_other) return R < other.R;
    return block_own < block_other;
  }
}query[maxn];

// for each query have to print the sum of each element * frequency * frequency
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> t;
  K = sqrt(n);
  for(int i = 1; i <= n; i++) cin >> a[i];

  for(int i =0; i < t; i++) {
    cin >> query[i].L >> query[i].R;
    query[i].index = i;
  }
  sort(query, query + t);

  int L = 1, R = 0;
  for(int i = 0; i < t; i++) {
    while(R < query[i].R) {
      ++R;
      sum -= (cnt[a[R]]*cnt[a[R]]*a[R]);
      ++cnt[a[R]];
      sum += (cnt[a[R]]*cnt[a[R]]*a[R]);
    }
    while(L < query[i].L) {
      sum -= (cnt[a[L]]*cnt[a[L]]*a[L]);
      --cnt[a[L]];
      sum += (cnt[a[L]]*cnt[a[L]]*a[L]);
      ++L;
    }
    while(R > query[i].R) {
      sum -= (cnt[a[R]]*cnt[a[R]]*a[R]);
      --cnt[a[R]];
      sum += (cnt[a[R]]*cnt[a[R]]*a[R]);
      R--;
    }
    while(L > query[i].L) {
      --L;
      sum -= (cnt[a[L]]*cnt[a[L]]*a[L]);
      ++cnt[a[L]];
      sum += (cnt[a[L]]*cnt[a[L]]*a[L]);
    }
    ans[query[i].index] = sum;
  }
  for(int i = 0; i < t; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}

