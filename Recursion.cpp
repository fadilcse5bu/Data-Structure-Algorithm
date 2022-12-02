#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;


int fact(int n)
{
    if(n==0)
        return 1;

    else
        return n*fact(n-1);
}

int main()
{
    int b,c,d,e,f,g,h,i,j,k=0,l=0,m,n,x,y;

    scanf("%d",&c);

    b=fact(c);

    printf("%d\n",b);

    //return 0;

}


