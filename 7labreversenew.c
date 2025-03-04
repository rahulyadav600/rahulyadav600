#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *start = NULL;
void create(node *p,int d) 
{

    if (p == NULL) {
        start = (node*)malloc(sizeof(node));
        start->data = d;
        start->next = NULL;
    }
else 
{
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = (node*)malloc(sizeof(node));
    p->next->data = d;
    p->next->next = NULL;
}
}
void disp(node *p)
{
    while(p!=NULL)
    {
    printf("%d ",p->data);
    p=p->next;
}
printf("\n");
}
void reverse(node *p)
{
    node *pre=NULL,*nxt=NULL;
    while(p!=NULL)
    {
        nxt=p->next;
        p->next=pre;
        pre=p;
        p=nxt;
    }
    start=pre;
}
  int main()
{
    create(start,10);
    create(start,20);
    create(start,30);
    create(start,40);
    create(start,50);
    create(start,60);
    printf("before rev:-\n");
    disp(start);
    printf("after rev:-\n");
    reverse(start);
    disp(start);

    getch();
}