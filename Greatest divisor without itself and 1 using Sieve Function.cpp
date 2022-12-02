#include<bits/stdc++.h>
using namespace std;

int greatest_divisor[6000000];
int adj[6000000];
void sieve(){
	for(int i = 2; i * i <= 5000000; i++){
		if(adj[i] == 0){
			for(int j = 2; j * i <= 5000000; j++){
				adj[i*j] = 1;
				greatest_divisor[i*j] = max(greatest_divisor[i*j], j);
			}
		}
	}
}

int main()
{
    sieve();
    for(int i = 1; i <= 100; i++){
        // if(greatest_divisor[i] == 0) it means i is a prime number
        cout << i << "-->" << greatest_divisor[i] << endl;
    }


    return 0;
}
