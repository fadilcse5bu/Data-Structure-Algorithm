///Bismillah

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector < pair < int , string > > p;

    for(int i = 0; i < n; i++){
        int a;
        string c;
        cin >> a >> c;
        p.push_back(make_pair(a,c));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(p[j + 1].first < p[j].first){
                swap(p[j + 1].first, p[j].first);
                swap(p[j + 1].second, p[j].second);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << p[i].first << " " << p[i].second << endl;
    }

    return 0;
}

///Alhumdulillah
