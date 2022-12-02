#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    ll n;
    cin>>n;

    ll a[n+1];
    for(ll i=0;i<n;i++) cin>>a[i];

    ll ans=a[0];
    for(ll i=1;i<n;i++){
        ll temp1=a[0],temp2=a[1],chk[2]={0,0};
        while(temp1 || temp2){
            ll p=temp1%2;
            ll q=temp2%2;

            chk[p^q]=q;

            temp1/=2;
            temp2/=2;
        }

        ans=a[chk[1]];
        chk[1]=!chk[1];
        swap(a[chk[1]],a[i+1]);
    }

    cout<<ans<<endl;

    return 0;
}
