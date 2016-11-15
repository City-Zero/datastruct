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

// 队列
typedef struct dui{
    struct node *data[Max];
    int head;
    int tail;
}Dui;

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

void go_in(Dui *bo,Node *root)
{
    bo->tail++;
    bo->data[bo->tail] = root;
}

void go_out(Dui *bo,Node **root)
{
    *root = bo->data[bo->head];
    bo->head++;
}

void ceng(Node *root)
{
    Dui *bo = malloc(sizeof(Dui));
    bo->head = 0;
    bo->tail = -1;
    Node *temp = root;
    go_in(bo,temp);
    while(bo->head <= bo->tail){
        go_out(bo,&temp);
        putchar(temp->data);
        if(temp->Lchild)
            go_in(bo,temp->Lchild);
        if(temp->Rchild)
            go_in(bo,temp->Rchild);
    }
}

int main(void)
{
    Node *root;
    xian_kuo_create(&root);
    ceng(root);
}
