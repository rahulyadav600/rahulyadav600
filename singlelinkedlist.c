#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *start = NULL;
void create(node *p)
{
    int d;
    printf("enter val for new node");
    scanf("%d", &d);

    if (p == NULL)
    {
        start = (node *)malloc(sizeof(node));
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
        p->next->data = d;
        p->next->next = NULL;
    }
}

void appbig(node *p)
{
    int d;
    printf("enter val for append big");
    scanf("%d", &d);
    start = (node *)malloc(sizeof(node));
    start->data = d;
    start->next = p;
}
void appmid(node *p)
{
    node *tmp;
    int d, pos;
    printf("enter val for mid node & pos");
    scanf("%d%d", &d, &pos);
    for (int i = 1; i <= pos - 2; i++)
    {
        p = p->next;
    }
    tmp = p->next;
    p->next = (node *)malloc(sizeof(node));
    p->next->data = d;
    p->next->next = tmp;
}

void delbig(node *p)
{
    start = start->next;
    free(p);
}
void delmid(node *p)
{
    node *tmp;
    int pos;
    printf("enter pos for del node");
    scanf("%d", &pos);
    for (int i = 1; i <= pos - 2; i++)
    {
        p = p->next;
    }
    tmp = p->next;
    p->next = p->next->next;
    free(tmp);
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
void disp(node *p)
{
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}
void search(node *p)
{
    int s, pos = 0, flag = 0;
    printf("enter search num");
    scanf("%d", &s);
    while (p != NULL)
    {
        pos = pos + 1;
        if (p->data == s)
        {
            flag = 1;
            printf("found at %d poistion", pos);
            break;
        }
        p = p->next;
    }
    if (flag == 0)
        printf("not found");
}

int main()
{
    char ch;
    int n;
    do
    {

        printf("Press 1 for create node \n");
        printf("Press 2 for app big \n");
        printf("Press 3 for app mid \n");
        printf("Press 4 for del big \n");
        printf("Press 5 for del mid \n");
        printf("Press 6 for del last \n");
        printf("Press 7 for display \n");
        printf("Press 8 for search \n");
        printf("Press any other key for exit \n");
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
            printf("invallid choise");
            getch();
            exit(0);
        }
        printf("\ndo you want to counti........(y/n)");
        fflush(stdin);
        scanf("%c", &ch);
    } while (ch != 'n');
    getch();
}