#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;


int main()
{
    int i,j,n,temp;
    scanf("%d",&n);
    int a[n];

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=1;i<n;i++){
        j=i;
        while(j>0&&a[j]<a[j-1]){
            temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;

            j--;
        }
    }

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}


