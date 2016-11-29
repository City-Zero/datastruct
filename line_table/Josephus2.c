/*************************************************************************
	> File Name: Josephus2.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月27日 星期二 17时33分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *next;
}Node;

void creat(Node *head,int n)
{
    int i;
    Node *tmp = head;
    for(i = 0;i < n;i++){
        Node *p = malloc(sizeof(Node));
        p->num = i + 1;
        tmp->next = p;
        tmp = p;
    }
    tmp->next = head->next;
}

void chudui(Node *head,int b[],int m,int n,int k)
{
    int i = 0;
    int j = 0;
    Node *tmp = head;
    Node *tt = head;
    while(tmp->next != tmp){
        tt = tmp;
        tmp = tmp->next;
        i++;
        if(i == m){
            tt->next = tmp->next;
            b[j] = tmp->num;
            j++;
            free(tmp);
            tmp = tt;
            i = 0;
            if(j == n - 1)
                break;
        }
    }
    b[j] = tmp->num;
    free(tmp);
}

int equal(int a[],int b[],int k,int n)
{
    int i;
    for(i = 0;i < k;i++){
        if(a[i] != b[n - k + i])
            return 0;
    }
    return 1;
}

int main(void)
{
    Node *head = malloc(sizeof(Node));
    int n,k;
    scanf("%d %d",&n,&k);
    int a[k],b[n];
    int i;
    for(i = 0;i < k;i++){
        scanf("%d",&a[i]);
    }
    for(i = 1;i <= n;i++){
        creat(head,n);
        chudui(head,b,i,n,k);
        if(equal(a,b,k,n)){
            printf("%d",i);
            return 0;
        }
    }
    printf("0");
    return 0;
}
