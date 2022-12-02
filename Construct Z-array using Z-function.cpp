#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int Z_array[1000006];

int main()
{
    string st;
    cin >> st;

    int L, R, k, n = st.size();
    L = R = 0;
    for(int i = 1; i < n; i++) {
        if(i > R) {
            L = R = i;
            while(R < n && st[R - L] == st[R]) R++;
            Z_array[i] = R - L;
            R--;
        }
        else {
            k = i - L;
            if(Z_array[k] < R - i + 1) Z_array[i] = Z_array[k];
            else {
                L = i;
                while(R < n && st[R - L] == st[R]) R++;
                Z_array[i] = R - L;
                R--;
            }
        }
    }

    for(int i = 1; i < n; i++)
        cout << Z_array[i] << ' ';


    return 0;
}
