#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>


using namespace std;
void InsertionSort(int arr[]);
int main()
{
    int a,i,j,k,l,m,n,t,arr[100];

    freopen("Saidul.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    a=arr[j];
                    arr[j]=arr[i];
                    arr[i]=a;
                }
            }
        }

        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }

    return 0;
}

void InsertionSort(int arr[])
{
    int a,i,j,k,l,m,n,t,arr[100];

    freopen("Saidul.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    a=arr[j];
                    arr[j]=arr[i];
                    arr[i]=a;
                }
            }
        }

        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }

    return 0;
}
