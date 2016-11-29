/*************************************************************************
	> File Name: Joseph_problem.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月08日 星期四 09时30分03秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *next;
}NODE;

void create(NODE *head,int n)
{
    int i=1;
    head->next = head;
    NODE *temp = head;
    while(i <= n) {
        NODE *p = (NODE*)malloc(sizeof(NODE));
        p->num = i;
        p->next = temp->next;
        temp->next = p;
        temp = p;
        i++;
    }
    temp->next = head->next;
}

void display(NODE *head)
{
    NODE *temp = head;
    while(temp->next != head->next) {
        printf("%d\n",temp->next->num);
        temp = temp->next;
    }
}

int win(NODE *head,int m)
{
    NODE *temp1;
    NODE *temp = head;
    int i = 0;
    while(temp->next != temp) {
        i++;
        temp1 = temp;
        temp = temp->next;
        if(i == m) {
            //sleep(1);
            i = 0;
            temp1->next = temp->next;
            printf("%d\n",temp->num);
            free(temp);
            temp = temp1;
        }
    }
    return temp->num;
}

int main(void)
{
    NODE *head = (NODE*)malloc(sizeof(NODE));
    int m,n;
    printf("请输入n和m的值(n,m>1):");
    scanf("%d %d",&n,&m);
    create(head,n);
    printf("获胜者是%d\n",win(head,m));
    return 0;
}
