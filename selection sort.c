//selection sort



#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int a[5],i,j,t,min;
    printf("enter a value in a:");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<4;i++)
    {
        min=i;
        for(j=i+1;j<5;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
   for(i=0;i<5;i++)
   {
    printf("%d",a[i]);
   }
   getch();
}