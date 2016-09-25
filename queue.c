/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月20日 星期二 13时41分19秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 10

typedef struct{
    int quelen;
    int rear;
    int elem[MaxSize];
}CSeQueue;  

int InQueue(CSeQueue *s,int a)
{
    if(s->quelen == MaxSize){
        puts("队满");
        return 0;
    }
    s->rear = (s->rear + 1) % MaxSize;
    s->elem[s->rear] = a;
    s->quelen++;
    return 1;
}

int OutQueue(CSeQueue *s,int *a)
{
    if(s->quelen == 0) {
        puts("队空");
        return 0;
    }
    *a = s->elem[s->rear - s->quelen + 1];
    s->quelen--;
    return 1;
}

int main(void)
{
    CSeQueue *s = (CSeQueue*)malloc(sizeof(CSeQueue));
    s->rear = 0;
    s->quelen = 0;
    memset(s->elem,0,sizeof(s->elem));

    int a;

    InQueue(s,10);
    InQueue(s,20);
    OutQueue(s,&a);
    printf("%d\n",a);
    OutQueue(s,&a);
    printf("%d\n",a);
    OutQueue(s,&a);
    printf("%d\n",a);
}

