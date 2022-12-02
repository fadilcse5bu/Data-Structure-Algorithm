#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    string st;

    while(n){
        int re = n % 26;
        n /= 26;
        if(re == 0){
            st.push_back('Z');
            --n;
        }
        else{
            st.push_back('A' + re - 1);
        }
    }

    reverse(st.begin(), st.end());
    cout << st;

}
