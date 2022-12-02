#include<bits/stdc++.h>
using namespace std;

int prime[20000005], ct[20000005];
bool col[20000005];

void sieve()
{
    for(int i = 2; i * i <= 20000000; i++) {\
        if(prime[i] == 0) {
            for(int j = 2; j * i <= 20000000; j++) {
                prime[i * j] = i;
                col[i * j] = true;
            }
        }
    }

    for(int i = 2; i * i <= 20000000; i++)
        if(col[i] == false) prime[i] = i;

}

int main()
{
    int n;
    cin >> n;
    int ar[n + 1];
    for(int i = 1; i <= n; i++) cin >> ar[i];

    sieve();

    for(int i = 1; i <= n; i++) {
        while(ar[i] > 1) {
            int v = prime[ar[i]];
            ct[v]++;
            while(ar[i] % v == 0) {
                ar[i] /= v;
            }
        }
    }

    for(int i = 2; i <= 20; i++) {
        if(col[i] == false) cout << "Prime Number: " << i << endl << "Number of elements are divisible: " << ct[i] << endl << endl;
    }

    return 0;
}
