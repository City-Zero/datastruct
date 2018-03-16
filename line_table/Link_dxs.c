/*************************************************************************
	> File Name: Link_dxs.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月25日 星期日 21时02分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int xishu;
    int cishu;
    struct node *next;
}Node;

void shuru(Node *a)
{
    int n;
    scanf("%d",&n);
    int i;
    int j,k;
    Node *tmp = a;
    for(i = 0;i < n;i++){
        Node *p = malloc(sizeof(Node));
        scanf("(%d,%d)",&p->xishu,&p->cishu);
        p->next = tmp->next;
        tmp->next = p;
        tmp = p;
    }
}

void display(Node *h)
{
    Node *temp;
    temp=h->next;
 
    while(temp->next)
    {
        if(temp->xishu==1);
        else if (temp->xishu  == -1)
        {
            printf("-");
        }
        else
            printf("%d",temp->xishu);
        if(temp ->cishu != 0)
        {
 
        printf("X");
        if(temp->cishu==1);
        else
        {
            printf("^");
            printf("%d",temp->cishu);
        }
        }
        if(temp->next ->xishu > 0)
        printf("+");
        temp=temp->next;
    }
    if(temp->xishu==1);
    else if(temp ->xishu == -1)
    printf("-");
    else
    printf("%d",temp ->xishu);
    if(temp ->cishu != 0)
    {
         
    printf("X");
    if(temp->cishu==1);
    else
    {
        printf("^");
        printf("%d",temp->cishu);
    }
 
    }
}

int main()
{
    Node *a = malloc(sizeof(Node));
    a->next = NULL;
    shuru(a);
    display(a);
}
