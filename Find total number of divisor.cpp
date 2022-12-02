#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*using u64 = uint64_t;
using u128 = __uint128_t;

u64 Pow(u64 n, u64 p, u64 m) {
	if(!p) return 1;
	else if(p & 1) return ((u128)n * Pow(n, p - 1, m)) % m;
	else {
		u64 v = Pow(n, p/2, m);
		return (u128)(v * v) % m;
	}
}

bool isprime(u64 n){
	if(n < 2) return false;
	for(u64 i = 2; i * i * i <= n; ++i) if(n % i == 0) return false;
	for(int it = 0; it < 1e5; ++it){
		u64 i = rand() % (n - 1) + 1;
		if(__gcd(i, n) != 1) return false;
		if(Pow(i, n-1, n) != 1) return false;
	}
	return true;
}*/


using u64 = uint64_t;
using u128 = __uint128_t;

vector <u64> ve;
bool ck[1000050];
void sieve()
{
    ve.push_back(2);
    for(u64 i = 2; i * 2 <= 1000010; i++) ck[i * 2] = true;
    for(u64 i = 3; i * i <= 1000010; i += 2){
        if(ck[i] == false){
            ve.push_back(i);
            for(u64 j = 2; j * i <= 1000010; j++){
                ck[j * i] = true;
            }
        }
    }

}

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}


int main()
{

    sieve();
    int t;
    cin >> t;
    while(t--){
        u64 n;
        cin >> n;

        u64 ans = 1;
        for(u64 i = 0; i < ve.size(); i++){
            u64 p = ve[i];
            if(p * p * p > n) break;
            u64 ct = 1;
            while(n % p == 0){
                n /= p;
                ++ct;
            }
            ans *= ct;

        }

        bool b = MillerRabin(n);
        u64 a = sqrt(n);
        if(b == true) ans *= 2;
        else if(a * a == n){
            bool c = MillerRabin(a);
            if(c == true) ans *= 3;
        }
        else if(n != 1) ans *= 4;

        cout << ans << endl;
    }

    return 0;
}
