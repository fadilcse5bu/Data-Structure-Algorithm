#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

  for(int i = 1; i < 20; i++) {
    cout << i << " -> ";
    // complexity of below loop is 3^n, where n is the number of set bit of i
    for(int s = i; s; s = (s-1)&i) {
      cout << s << ' ';
    }
    cout << endl;
  }

  return 0;
}


