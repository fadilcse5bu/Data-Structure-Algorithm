#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;


int gcd(int n,int m)
{
    if(m==0)
        return n;
    else
        return gcd(m,n%m);
}

int main()
{
    int b,c,d,e,f,g,h,i,j,k=0,l=0,m,n,x,y;

    scanf("%d %d",&c,&d);



    b=gcd(c,d);

    printf("%d\n",b);

    //return 0;

}



