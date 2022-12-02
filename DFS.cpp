///Bismillah
#define WHITE 1
#define GRAY 2
#define BLACK 3

#include<bits/stdc++.h>
using namespace std;

int node, edge;
int adj[100][100];
int color[100];
int finishingtime[100];
int startingtime[100];
int parent[100];

int t = 1;

void dfsvisit(int x){
    color[x] = GRAY;
    //startingtime[x] = t;
    //t++;

    for(int i = 0; i < node; ++i){
        if(adj[x][i] == 1){
            if(color[i] == WHITE){
                //parent[i] = x;
                dfsvisit(i);
            }
        }
    }

    color[x] = BLACK;
    //finishingtime[x] = t;
    //t++;
}

void dfs(){
    for(int i = 0; i < node; i++){
        color[i] = WHITE;
        //parent[i] = -1;
    }
    for(int i = 0; i < node; i++){
        if(color[i] == WHITE){
            dfsvisit(i);
        }
    }
}

int main()
{
    //freopen("Input.txt", "r", stdin);
    cin >> node >> edge;
    int n1, n2;
    for(int i = 0; i < edge; i++){
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }
    dfs();

    //cout << parent[6];

    return 0;
}
