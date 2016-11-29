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

int size;
char xian[50];
char zhong[50];

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

int find_z(char ch)
{
	int i;
	for(i = 0;i < size;i++){
		if(zhong[i] == ch)
			return i;
	}
}

int find_x(char ch)
{
	int i;
	for(i = 0;i < size;i++){
		if(xian[i] == ch)
			return i;
	}
}
void create(Node **root,char *x,char *z,int len)
{
	if(len == 0) {
		(*root) = NULL;
		return ;
	}
	(*root) = malloc(sizoeof(Node));
	(*root)->data = *x;
	int num_z = find_z(*x);
	int num_x = find_x(*x);
	create(&((*root)->Lchild),xian[num_x + 1],zhong[0],find_z - find_x);
	create(&((*root)->Rchild),xian[num_z + 1],zhong[],len - num_z - 1);
}

int main(void)
{
	size = strlen(xian);
    scanf("%s %s",xian,zhong);
    Node *root;
    create(&root,xian,zhong,size);
    no_hou(root);
}
