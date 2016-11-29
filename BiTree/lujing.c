#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 100
#define NUM 20

typedef struct node{
    char data;
    struct node *Lchild;
    struct node *Rchild;
}Node;

// Таѕ
typedef struct zhan{
    struct node *data[Max];
    int top;
}Zhan;

char get_parent(Node *root,char p);

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

void fand_leave(Node *root)
{
    char leave[NUM];
    memset(leave,0,sizeof(leave));
    Zhan *bottle = malloc(sizeof(Zhan));
    bottle->top = -1;
    Node *temp = root;
    int i = 0;
    while(temp || bottle->top != -1){
        if(temp){
            if(!temp->Lchild && !temp->Rchild){
                leave[i] = temp->data;
                i++;
            }
            push(bottle,temp);
            temp = temp->Lchild;
        } else{
            pop(bottle,&temp);
            temp = temp->Rchild;
        }
    }
    int n = strlen(leave);
    char lujing[n][NUM/2];
    for(i = 0;i < n;i++)
    memset(lujing[i],0,sizeof(n*NUM/2));
    char t1;
    int j;
    for(i = 0;i < n;i++){
        t1 = leave[i];
        j = 0;
	    while(t1 != root->data){
		    t1 = get_parent(root,t1);
		    lujing[i][j] = t1;
		    j++;
	    }
    }
    for(i = 0;i < n;i++){
        putchar(leave[i]);
        putchar(':');
        for(j = strlen(lujing[i]) - 1;j >= 0;j--){
            putchar(lujing[i][j]);
        }
        puts("");
    }
}

char get_parent(Node *root,char p)
{
    Zhan *bottle = malloc(sizeof(Zhan));
    bottle->top = -1;
    Node *temp = root;
    while(temp || bottle->top != -1){
        if(temp){
			if((temp->Lchild &&temp->Lchild->data == p) || (temp->Rchild && temp->Rchild->data == p)){
				return temp->data;
			}
            push(bottle,temp);
            temp = temp->Lchild;
        } else{
            pop(bottle,&temp);
            temp = temp->Rchild;
        }
    }
}

int main(void)
{
    Node *root;
    xian_kuo_create(&root);
    fand_leave(root);
    return 0;
}
