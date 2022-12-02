///Bismillah

#include<bits/stdc++.h>
using namespace std;

vector <int> ve(1000, 0);
int adj[1000][1000], cost[1000][1000], co[1000];
set <pair <int, int> > s;
set <pair <int, int> > :: iterator I;
int main()
{

    priority_queue <pair <int, int> > pq;

    int v, e;
    cin >> v >> e;

    for(int i = 0; i < v; i++) co[i] = INT_MAX;
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = 1;
        adj[b][a] = 1;
        cost[a][b] = c;
        cost[b][a] = c;
    }

    int c[100] = {0};
    int col[v] = {0};
    pq.push(make_pair(0, 0));
    long long int re = 0;
    while(!pq.empty()){
        int x = pq.top().first;
        int y = pq.top().second;
        cout << x << ' ' << y << endl;
        pq.pop();
        if(col[x] == 0){
        for(int i = 0; i < v; i++){
            if(adj[x][i] == 1){
                if(col[i] == 0){
                    if(cost[x][i] < co[i]){
                        co[i] = cost[x][i];
                        pq.push(make_pair(i, co[i]));
                    }
                }
            }
        }

        col[x] = 1;
        }
        re += y;
    }

    cout << re;

    return 0;
}

///Alhumdulillah
