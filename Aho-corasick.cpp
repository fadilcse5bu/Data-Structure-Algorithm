using namespace std;
#include <bits/stdc++.h>

int g[500][27], f[500];
int endP[500];
vector <int> match[500];

void build_trie(string arr[], int k) {
  int state = 0;
  for(int i = 0; i < k; i++) {
    int cur_st = 0;
    for(int j = 0; j < arr[i].size(); j++) {
      int ch = arr[i][j] - 'a';
      if(g[cur_st][ch] == -1) {
        g[cur_st][ch] = ++state;
      }
      cur_st = g[cur_st][ch];
    }
    endP[cur_st] |= (1 << i);
  }

  for(int ch = 0; ch < 27; ch++) {
    if(g[0][ch] == -1) g[0][ch] = 0;
  }
}

void failure_function() {
  queue <int> q;
  for(int ch = 0; ch < 27; ch++) {
    if(g[0][ch] != 0) {
      f[g[0][ch]] = 0;
      q.push(g[0][ch]);
    }
  }

  while(!q.empty()) {
    int state = q.front();
    q.pop();
    for(int ch = 0; ch < 27; ch++) {
      if(g[state][ch] != -1) {
        int failure = f[state];
        while(g[failure][ch] == -1) {
          failure = f[failure];
        }
        failure = g[failure][ch];
        f[g[state][ch]] = failure;
        q.push(g[state][ch]);
        endP[g[state][ch]] |= endP[failure];
      }
    }
  }
}

int findNextState(int cur_st, char ch) {
  int v = ch - 'a';
  while(g[cur_st][v] == -1) {
    cur_st = f[cur_st];
  }
  return g[cur_st][v];
}

void searchWords(string arr[], int k, string text) {
  int cur_st = 0;
  for(int i = 0; i < text.size(); i++) {
    cur_st = findNextState(cur_st, text[i]);
    if(endP[cur_st] == 0) continue;
    for(int j = 0; j < k; j++) {
      if(endP[cur_st] & (1 << j)) {
        cout << arr[j] << ' ';
      }
    }
  }
}

int main()
{
    string arr[] = {"he", "she", "his", "hers"};
    string text = "ahishers";
    int k = sizeof(arr)/sizeof(arr[0]);

    memset(g, -1, sizeof(g));
    memset(f, -1, sizeof(f));

    build_trie(arr, k);
    failure_function();
    searchWords(arr, k, text);


    return 0;
}

