// bubble sort

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    int a[5], i, j, t;
    printf("enter valuein a:");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5 - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d", a[i]);
    }
    getch();
}