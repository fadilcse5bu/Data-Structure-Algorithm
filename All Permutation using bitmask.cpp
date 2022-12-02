#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n;
string s;
void recurse(int mask,int taken, string pref){
  if(taken == n){
    cout << pref <<endl;
    return;
  }
  for(int i = 0; i < n; i++){
    if(((mask >> i) & 1) == 0){
      recurse((mask | (1 << i)),taken + 1, pref + s[i]);
    }
  }
}

int main()
{
  n = 3;
  s = "abc";
  recurse(0, 0, "");

  return 0;
}

