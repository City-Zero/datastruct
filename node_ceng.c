/*************************************************************************
	> File Name: create_BTree.c
	> Author: 
	> Mail: 
	> Created Time: Fri Nov 11 10:26:32 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node *Lchild;
    struct node *Rchild;
}Node;

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

void print(Node *root,int *nu)
{
    (*nu)++;
    if(!root) ;
    else {
    printf("(%c,%d)",root->data,*nu);
    print(root->Lchild,&(*nu));
    print(root->Rchild,&(*nu));
    }
    (*nu)--;
}

int main(void)
{
    Node *root;
    xian_kuo_create(&root);
    int nu = 0;
    print(root,&nu);
}
