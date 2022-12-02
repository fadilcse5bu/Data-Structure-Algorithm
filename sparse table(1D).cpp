#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int stable[100005][20];

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    int n, q, a;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
      scanf("%d", &a);
      stable[i][0] = a;
    }

    for(int k = 1; (1 << k) <= n; k++) {
      for(int i = 1; i + (1<<k) - 1 <= n; i++) {
        stable[i][k] = min(stable[i][k-1], stable[i+(1<<(k-1))][k-1]);
      }
    }

    printf("Scenario #%d:\n", cs++);
    while(q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      int len = (r - l + 1);
      int k = log2(len);
      int ans = min(stable[l][k], stable[r-(1<<k)+1][k]);
      printf("%d\n", ans);
    }
  }

  return 0;
}


