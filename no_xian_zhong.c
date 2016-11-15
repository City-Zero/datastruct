/*************************************************************************
	> File Name: create_BTree.c
	> Author: 
	> Mail: 
	> Created Time: Fri Nov 11 10:26:32 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

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

void no_zhong(Node *root)
{
    Zhan *bottle = malloc(sizeof(Zhan));
    bottle->top = -1;
    Node *temp = root;
    while(temp || bottle->top != -1){
        if(temp){
            push(bottle,temp);
            temp = temp->Lchild;
        } else{
            pop(bottle,&temp);
            putchar(temp->data);
            temp = temp->Rchild;
        }
    }
}

void no_xian(Node *root)
{
    Zhan *bottle = malloc(sizeof(Zhan));
    bottle->top = -1;
    Node *temp = root;
    while(temp || bottle->top != -1){
        if(temp){
            putchar(temp->data);
            push(bottle,temp);
            temp = temp->Lchild;
        } else{
            pop(bottle,&temp);
            temp = temp->Rchild;
        }
    }
    puts("");
}

int main(void)
{
    Node *root;
    xian_kuo_create(&root);
    no_xian(root);
    no_zhong(root);
}
