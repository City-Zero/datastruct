/*************************************************************************
	> File Name: Linklist_cut.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月09日 星期五 08时40分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *next;
} NODE;

int main(void)
{
    NODE *head = (NODE*) malloc(sizeof(NODE));
    head->next = NULL;
    NODE *temp = head;
    printf("请输入一串数(输入0即停止):");
    int a;
    scanf("%d",&a);
    while(a != 0) {
        NODE *p = (NODE*)malloc(sizeof(NODE));
        p->num = a;
        p->next = temp->next;
        temp->next = p;
        temp = p;
        scanf("%d",&a);
    }

    NODE *tt;
    NODE *one = head->next;
    tt = one;
    temp = tt->next;
    while(temp){
        printf("%d\n",temp->num);
        if(temp->num < one->num) {
            tt->next = temp->next;
            temp->next = head->next;
            head->next = temp;
        }else {
            tt = tt->next;
        }
        temp = tt->next;
    }

    temp = head->next;
    while(temp) {
        printf("%d ",temp->num);
        temp = temp->next;
    }
    puts("");
    return 0;
}
