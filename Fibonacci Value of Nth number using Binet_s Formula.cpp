#include<bits/stdc++.h>
using namespace std;

//fib(n) = ((1 + sqrt(5))^n - (1 - sqrt(5))^n) / (2^n * sqrt(5))
//Where n <= 92;

long long fibo[100005];
double binet(int n){
    double phi = (1 + sqrt(5));
    double phi1 = (1 - sqrt(5));
    double re = pow(2, n) * sqrt(5);
    double fib = (pow(phi,n) - pow(phi1,n))/re;
    long long f = fib;
    fibo[n] = f;
    return round(f);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        long long a = binet(i);
    }
    for(int i = 1; i <= n; i++){
        cout << fibo[i] << ' ';
    }
}
