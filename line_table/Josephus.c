/*************************************************************************
	> File Name: Josephus.c
	> Author: 
	> Mail: 
	> Created Time: Fri Sep 23 10:32:12 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int hao;
    int num;
    struct node *next;
}Node;

int main(void)
{
    Node *head = malloc(sizeof(Node));
    int n,m;
    scanf("%d %d",&n,&m);
    int i;
    Node *temp = head;
    for(i = 0;i < n;i++){
        Node *p = malloc(sizeof(Node));
        temp->next = p;
        temp = p;
        scanf("%d",&p->num);
        p->hao  = i+1;
    }
    temp->next = head->next;
    i = 0;
    Node *tt = head;
    temp = head;
    while(temp->next != temp){
        tt = temp;
        i++;
        temp = temp->next;
        if(i == m){
            printf("%d ",temp->hao);
            m = temp->num;
            i = 0;
            tt->next = temp->next;
            free(temp);
            temp = tt;
        }
    }
    printf("%d",temp->hao);
    return 0;
}
