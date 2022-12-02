#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int ar[], int len, int sum) {
    bool subset[2][sum + 1];
    subset[0][0] = true, subset[1][0] = true;
    for(int i = 1; i <= sum; i++) subset[0][i] = false;

    for(int i = 0; i < len; i++) {
        for(int j = 0; j <= sum; j++) {
            if(j < ar[i]) subset[1][j] = subset[0][j];
            else subset[1][j] = subset[0][j] || subset[0][j - ar[i]];
        }

        for(int j = 0; j <= sum; j++) subset[0][j] = subset[1][j];
    }

    return subset[1][sum];
}


int main()
{
    int n;
    cin >> n;
    int ar[n];
    for(int i = 0; i < n; i++) cin >> ar[i];

    cout << isSubsetSum(ar, n, 5);

    return 0;
}
