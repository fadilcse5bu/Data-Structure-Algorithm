#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;


void TOH(int n,char sou,char aux,char tar)
{
    if(n==1){
        return;
    }
    TOH(n-1,sou,tar,aux);
    printf("%c---->%c\n",sou,tar);
    TOH(n-1,aux,sou,tar);
}

int main()
{
    int b,c,d,e,f,g,h,i,j,k=0,l=0,m,n,x,y;
    char sou='A';
    char aux='B';
    char tar='C';

    //scanf("%d",&c);

    TOH(5,sou,aux,tar);

    //printf("%d\n",b);

    //return 0;

}


