/*************************************************************************
	> File Name: create_BTree.c
	> Author: 
	> Mail: 
	> Created Time: Fri Nov 11 10:26:32 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 100

typedef struct node{
    char data;
    struct node *Lchild;
    struct node *Rchild;
}Node;

// 栈
typedef struct zhan{
    struct node *data[Max];
    int top;
}Zhan;

void xian_kuo_create(Node **root)
{
    char ch;
    ch=getchar();
    if(ch == '#') *root = NULL;
    else{
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = ch;
        xian_kuo_create(&((*root)->Lchild));
        xian_kuo_create(&((*root)->Rchild));
    }
}

void push(Zhan *bottle,Node *root)
{
    bottle->top++;
    bottle->data[bottle->top] = root;
}

int pop(Zhan *bottle,Node **root)
{
    *root = bottle->data[bottle->top];
    bottle->top--;
    if(bottle->top == -1)
        return 1;
    return 0;
}

void no_hou(Node *root)
{
    Zhan *bottle = malloc(sizeof(Zhan));
    bottle->top = -1;
    Node *temp = root;
    Node *tt = NULL;
    while(temp || bottle->top != -1){
        while(temp){
            push(bottle,temp);
            temp = temp->Lchild;
        }
        if(bottle->top != -1){
            temp = bottle->data[bottle->top];
            if(!temp->Rchild || temp->Rchild == tt){
                pop(bottle,&temp);
                putchar(temp->data);
                tt = temp;
                temp = NULL;
            } else 
                temp = temp->Rchild;
        }
    }
}

int find(char *s,char a)
{
    int i = 0;
    while(s[i] != a){
        i++;
    }
    return i;
}

void create(Node **root,char *xian,char *zhong,int *a)
{
    if(*a == strlen(xian) - 1) {
        (*root) = NULL;
        return;
    }
    (*root) = malloc(sizeof(Node));
    (*root)->data = xian[*a];
    int b = find(zhong,xian[*a]);
    if(b > *a){
        (*a)++;
        create(&((*root)->Lchild),xian,zhong,&(*a));
    } else if(b == *a){
        (*a)++;
        (*root)->Lchild = NULL;
        create(&((*root)->Rchild),xian,zhong,&(*a));
    } else {
        (*a)++;
        (*root)->Lchild = NULL;
        (*root)->Rchild = NULL;
    }
}

int main(void)
{
    char xian[50];
    char zhong[50];
    scanf("%s %s",xian,zhong);
    Node *root;
    int a = 0;
    create(&root,xian,zhong,&a);
    no_hou(root);
}
