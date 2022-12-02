#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100000001

bool Check(int n, int pos) {
  return (bool)(n & (1<<pos));
}
int Set(int n, int pos) {
  return n = n | (1<<pos);
}

int status[mx/32 + 2], ct = 1;

void bitwise_Sieve(int n) {
  int sq = sqrt(n);
  for(int i = 3; i <= sq; i += 2) {
    if(Check(status[i/32], i%32) == 0) {
      ++ct;
      for(ll j = i*i; j <= n; j += 2*i) {
        status[j/32] = Set(status[j/32], j%32);
      }
    }
  }
  for(int i = 3; i <= n; i += 2) {
    if(Check(status[i/32], i%32) == 0) {
      ++ct;
    }
  }
}

int main()
{
  bitwise_Sieve(100000000);
  cout << ct << endl;

  return 0;
}
