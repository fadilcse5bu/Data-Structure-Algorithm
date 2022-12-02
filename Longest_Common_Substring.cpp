#include <bits/stdc++.h>
using namespace std;

// The idea is to find the length of the longest common suffix
// for all substrings of both strings and store these lengths in a table.
int LCSubStr(string s, string t, int n, int m)
{
  int dp[2][m + 1];
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
        if (dp[i % 2][j] > res)
          res = dp[i % 2][j];
      }
      else
        dp[i % 2][j] = 0;
    }
  }
  return res;
}

int main()
{
    string X = "OldSite:GeeksforGeeks.org";
    string Y = "NewSite:GeeksQuiz.com";

    int m = X.length();
    int n = Y.length();

    cout << LCSubStr(X, Y, m, n);
    return 0;
}

