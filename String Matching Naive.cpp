#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;


int main()
{
    /*int b,c,d,e,f=0,g,h,i,j,k=0,l,m,n,x,y,max=0;
    char T[1000],P[1000];
    gets(T);
    gets(P);
    l=strlen(T);
    m=strlen(P);

    for(i=0;i<l-2;i++){
        b=i;
        for(j=0;j<m;j++){
            if(T[b]==P[j]){
                b++;
                f++;

                if(f==m){
                    printf("YES\n%d",i);
                    return 0;
                }
            }
            else
                f=0;
        }
    }
    printf("NO\n");*/




    int b=0,c,d,e,f=0,g,h,i,j,k=0,l,m,n,x,y,max=0;
    char T[1000],P[1000];
    gets(T);
    gets(P);
    l=strlen(T);
    m=strlen(P);

    for(i=0;i<l-2;i++){
        for(j=i;j<i+m;j++){
            if(T[j]==P[b]){
                f++;

                if(f==m){
                    printf("YES\n%d",i);
                    return 0;
                }
            }
            else
                f=0;

            b++;
        }
        b=0;
    }
    printf("NO\n");


    return 0;
}


