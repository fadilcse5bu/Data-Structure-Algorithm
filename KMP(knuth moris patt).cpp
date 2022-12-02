#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int lps[1000005]; //lps = longest prefix suffix
vector <int> matchingIndex;

void computeLps(string st) {
  // lps -> starting index 1
  int len = 0, i = 2;
  while(i <= st.size()) {
    if(st[i - 1] == st[len]) {
      lps[i] = len + 1;
      ++len;
      ++i;
    }
    else {
      if(len == 0) ++i;
      else len = lps[len - 1];
    }
  }
}

void findMatching(string t, string p) {
  computeLps(p);
  int j = 0, i = 0;
  while(i < t.size()) {
    if(t[i] == p[j]) {
      ++i;
      ++j;
    }
    if(j == p.size()) {
      matchingIndex.push_back(i - j);
      j = lps[j];
    }
    else if(i < t.size() and t[i] != p[j]) {
      if(j != 0) j = lps[j];
      else ++i;
    }
  }
}

int main()
{
  string t, p;
  cin >> t >> p;

  findMatching(t, p);

  cout << matchingIndex.size() << endl;
  for(int i = 0; i < matchingIndex.size(); i++) cout << matchingIndex[i] << ' ';

  return 0;
}



