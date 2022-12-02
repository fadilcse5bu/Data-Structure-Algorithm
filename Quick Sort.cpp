/*BISMILLAHI TAWAKKALTU ALALLAH*/
/*There is no god without ALLAH
and Hazrat Muhammad Sallallahu Alihi Oasallam is The Messenger of ALLAH*/
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int Partition(int A[],int p,int r)
{
    int i=p-1;
    //int x=A[r];
    for(int j=p;j<r;j++){
        if(A[j]<=A[r]){
            i++;
            int t=A[i];
            A[i]=A[j];
            A[j]=t;
        }
    }

    int t1=A[i+1];
    A[i+1]=A[r];
    A[r]=t1;

    return i+1;
}

void QuickSort(int A[],int p,int r)
{
    if(p<r){
        int q=Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }

}


int main()
{
    long long int b,c,d,e,f=0,g,h,i,j,k=0,l,m,n,x,y,max=0,p,r;

    cin>>n;

    int A[n];

    for(i=0;i<n;i++){
        cin>>A[i];
    }

    p=0;
    r=n-1;

    QuickSort(A,p,r);

    for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}


