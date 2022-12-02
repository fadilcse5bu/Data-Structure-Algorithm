#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
    int n,i,j,max=0;
    scanf("%d",&n);
    int a[n+1],a2[n+1];
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>max)
            max=a[i];
    }

    int a1[max+1]={0};

    for(i=1;i<=n;i++){
        a1[a[i]]++;
    }

    for(i=2;i<max+1;i++){
        a1[i]=a1[i]+a1[i-1];
    }

    for(i=1;i<=n;i++){
        a2[a1[a[i]]]=a[i];
        a1[a[i]]--;
    }

    for(i=1;i<=n;i++){
        printf("%d ",a2[i]);
    }


    return 0;
}

