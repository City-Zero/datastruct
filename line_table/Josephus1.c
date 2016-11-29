/*************************************************************************
	> File Name: Josephus.c
	> Author: 
	> Mail: 
	> Created Time: Fri Sep 23 10:32:12 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int num;
    struct node *next;
}Node;

void creat(Node *head,int n)
{
    int i;
    Node *tmp = head;
    for(i = 0;i < n;i++){
        Node *p = malloc(sizeof(Node));
        p->num = i + 1;
        tmp->next = p;
        tmp = p;
    }
    tmp->next = head->next;
}

void chudui(Node *head,int m)
{
    int i = 0;
    Node *temp = head;
    Node *tt = head;
    while(temp->next != temp){
        tt = temp;
        i++;
        temp = temp->next;
        if(i == m){
            printf("%d ",temp->num);
            i = 0;
            tt->next = temp->next;
            free(temp);
            temp = tt;
        }
    }
    printf("%d",temp->num);
}

int main(void)
{
    Node *head = malloc(sizeof(Node));
    int m,n;
    scanf("%d %d",&n,&m);
    creat(head,n);
    chudui(head,m);
    return 0;
}
