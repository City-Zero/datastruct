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

int Le_No_Num = 0;  //叶子节点个数
int du_2 = 0;       //度为２节点个数
int du_1 = 0;       //度为１节点个数

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

void leaf_node_num(Node *root)  //统计数目
{
    if(root == NULL) return;
    if(root->Lchild == NULL && root->Rchild == NULL){
        Le_No_Num++;
    } else{
        if(root->Lchild && root->Rchild)
            du_2 ++;
        else if(root->Lchild || root->Rchild)
            du_1 ++;
        leaf_node_num(root->Lchild);
        leaf_node_num(root->Rchild);
    }
}
void leaf_node(Node *root)  //输出叶子节点
{
    if(root == NULL) return;
    if(root->Lchild == NULL && root->Rchild == NULL){
        putchar(root->data);
    } else{
        leaf_node(root->Lchild);
        leaf_node(root->Rchild);
    }
}

int main(void)
{
    Node *root;
    xian_kuo_create(&root);
    leaf_node_num(root);
    printf("%d %d %d\n",Le_No_Num,du_1,du_2);
    leaf_node(root);
}
