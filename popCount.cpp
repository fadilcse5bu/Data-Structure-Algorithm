#include<bits/stdc++.h>
using namespace std;

int popCount1(unsigned x) {
  x -= ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x + (x >> 4)) & 0x0F0F0F0F;
  x += (x >> 8);
  x += (x >> 16);
  return x & 0x0000003F;
}

long long int popCount2(unsigned x) {
  unsigned long long y;
  y = x * 0x0002000400080010ULL;
  y = y & 0x1111111111111111ULL;
  y = y * 0x1111111111111111ULL;
  y = y >> 60;
  return y;
}

int main()
{
  cout << popCount1(3) << endl;
  cout << popCount2(3907788768766876) << endl;
  cout << __builtin_popcount(3878968765757575765);

  return 0;
}
