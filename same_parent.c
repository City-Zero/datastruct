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

void same_parent(Node *root,char c1,char c2)
{
	char t1 = c1,t2 = c2;
	char td1[NUM],td2[NUM];
	int i = 0;
	while(t1 != root->data){
		t1 = get_parent(root,t1);
		td1[i] = t1;
		i++;
	}
	i = 0;
	while(t2 != root->data){
		t2 = get_parent(root,t2);
		td2[i] = t2;
		i++;
	}
	int j;
	int l1 = strlen(td1);
	int l2 = strlen(td2);
	for(i = 0;i < l1;i++){
		for(j = 0;j<l2;j++){
			if(td1[i] == td2[j]){
				putchar(td1[i]);
				return;
			}
		}
	}
}

int main(void)
{
    Node *root;
    xian_kuo_create(&root);
	char c1,c2;
	c1 = getchar();
	scanf("%c %c",&c1,&c2);
	same_parent(root,c1,c2);
}
