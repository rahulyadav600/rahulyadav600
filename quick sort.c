// quick sort




#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int split(int a[],int l,int u)
{
    int t;
    int piv=a[l];
    int i=l+1;
    int j=u;
    while(j>=i)
    {
        while(a[i]<piv)
        {
            i=i+1;
        }
        while(a[j]>piv)
        {
            j=j-1;
        }
        if(j>i)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[j];
    a[j]=a[l];
    a[l]=t;
    return j;
}
void quickshort ( int a[],int l,int u)
{
    if(l<u)
    {
        int pos=split(a,l,u);
        quickshort(a,l,pos-1);
        quickshort(a,u,pos+1);

    }
}
int main()
{
    int a[10],i;
    printf("enter value");
    for(i=0;i<10;i++)
    {
       scanf("%d",&a[i]);
    }
    quickshort(a,0,9);
    for(i=0;i<10;i++){
       printf("%d",a[i]);
    }
    return 0;
}