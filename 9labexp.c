#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    struct node *pre;
    int data;
    struct node *next;
} node;

node *start = NULL;

void create(node *p)
{
    int d;
    printf("Enter value for new node: ");
    scanf("%d", &d);

    if (p == NULL)
    {
        start = (node *)malloc(sizeof(node));
        start->pre = NULL;
        start->data = d;
        start->next = NULL;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = (node *)malloc(sizeof(node));
        p->next->pre = p;
        p->next->data = d;
        p->next->next = NULL;
    }
}

void appbig(node *p)
{
    int d;
    printf("Enter value for start node: ");
    scanf("%d", &d);

    start = (node *)malloc(sizeof(node));
    start->data = d;
    start->pre = NULL;
    start->next = p;
    p->pre = start;
}

void appmid(node *p)
{
    int d, pos, i;
    node *tmp;
    printf("Enter value and pos for new node: ");
    scanf("%d%d", &d, &pos);

    for (i = 1; i <= pos - 2; i++)
    {
        p = p->next;
    }
    tmp = p->next;
    p->next = (node *)malloc(sizeof(node));
    p->next->pre = p;
    p->next->data = d;
    p->next->next = tmp;
    tmp->pre = p->next;
}

void delbig(node *p)
{

    start = start->next;
    start->pre = NULL;
    free(p);
}

void dellast(node *p)
{

    while (p->next->next != NULL)
    {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

void delmid(node *p)
{
    int pos, i;
    node *tmp;
    printf("Enter pos for delete node: ");
    scanf("%d", &pos);

    for (i = 1; i <= pos - 2; i++)
    {
        p = p->next;
    }
    tmp = p->next;
    p->next = p->next->next;
    p->next->pre = p;
    free(tmp);
}

void disp(node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void search(node *p)
{
    int s, c = 0, flag = 0;
    printf("Enter value for search node: ");
    scanf("%d", &s);

    while (p != NULL)
    {
        c = c + 1;
        if (s == p->data)
        {
            printf("Found at position %d\n", c);
            flag = 1;
            break;
        }
        p = p->next;
    }

    if (flag == 0)
        printf("Value not found\n");
}

int main()
{
    int n;
    char ch;

    do
    {
    
        printf("Press 1 for create\n");
        printf("Press 2 for appbig\n");
        printf("Press 3 for appmid\n");
        printf("Press 4 for delbig\n");
        printf("Press 5 for delmid\n");
        printf("Press 6 for dellast\n");
        printf("Press 7 for disp\n");
        printf("Press 8 for search\n");
        printf("Press any other for exit\n");

        scanf("%d", &n);

        if (n == 1)
            create(start);
        else if (n == 2)
            appbig(start);
        else if (n == 3)
            appmid(start);
        else if (n == 4)
            delbig(start);
        else if (n == 5)
            delmid(start);
        else if (n == 6)
            dellast(start);
        else if (n == 7)
            disp(start);
        else if (n == 8)
            search(start);
        else
        {
            printf("Invalid choice\n");
            getch();
            exit(0);
        }

        printf("Do u want to continue? (y/n): ");
        fflush(stdin);
        scanf(" %c", &ch);
    } while (ch != 'n');

    getch();
}