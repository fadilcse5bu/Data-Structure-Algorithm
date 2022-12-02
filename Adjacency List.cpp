///Bismillah

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int vertices;
    cin >> vertices;

    vector <int> adj[vertices];
    vector<int > :: iterator I;

    int edges;
    cin >> edges;

    for(int i = 0; i < edges; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < vertices; i++){
        //cout << adj[i].size() << endl;
        /*for(I = adj[i].begin(); I < adj[i].end(); I++){
            cout << *I << endl;
        }*/

        for(int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << endl;
        }

    }

    return 0;
}

///Alhumdulillah
