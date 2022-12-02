///Bismillah

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ar[10] = {1, -2, 5, 3, -5, 4, -8, 3, 9, -1};

    int sum  = ar[0];
    int check = ar[0];
    for(int i = 1; i < 10; i++){
        check += ar[i];
        if(check < 0) check = 0;
        else{
            if(check > sum) sum = check;
        }
    }

    cout << sum;


    return 0;
}

///Alhumdulillah
