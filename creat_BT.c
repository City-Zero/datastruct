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

void xian_print(Node *root)
{
    if(root == NULL) ;
    else {
        putchar(root->data);
        xian_print(root->Lchild);
        xian_print(root->Rchild);
    }
}
void zhong_print(Node *root)
{
    if(root == NULL) ;
    else {
        zhong_print(root->Lchild);
        putchar(root->data);
        zhong_print(root->Rchild);
    }
}
void hou_print(Node *root)
{
    if(root == NULL) ;
    else {
        hou_print(root->Lchild);
        hou_print(root->Rchild);
        putchar(root->data);
    }
}
int main(void)
{
    Node *root;
    xian_kuo_create(&root);
    xian_print(root);
    puts("");
    zhong_print(root);
    puts("");
    hou_print(root);
}
