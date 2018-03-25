#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct btree{
    char data;
    struct btree *l;
    struct btree *r;
}Btree;

typedef struct queue{
    Btree *data;
    struct queue *next;
}Queue;

Btree *create(){
    char c;
    do{
        scanf("%c",&c);
    }while(c=='\n' || c=='\r');
    //setbuf(stdin,NULL);
    Btree *t = NULL;
    if(c!='#'){
        t = malloc(sizeof(Btree));
        t->data = c;
        t->l = create();
        t->r = create();
    }
    return t;
    
}

void print(Btree *root){
    if(root){
        
        print(root->l);
        printf("%c",root->data);
        print(root->r);

    }
}

void push(Queue *q,Btree *root){
    //puts("push");
    Queue *end = q;
    while(end->next)
        end = end->next;
    Queue *t = malloc(sizeof(Queue));
    end->next = t;
    t->data = root;
    t->next = NULL;
}

Btree* pop(Queue *q){
    //puts("pop");
    Btree *t = q->next->data;
    Queue *qt = q->next;
    q->next = qt->next;
    free(qt);
    return t;
}

void ceng_print(Btree *root,Queue *q){
    push(q,root);
    //puts("in ceng");
    while(q->next){
        //puts("in while");
        Btree *t = pop(q);
        printf("%c\n",t->data);
        //sleep(1);
        if(t->l)
            push(q,t->l);
        if(t->r)
            push(q,t->r);
    }
}

int main(void){
    char c;
    Btree *root;
    root = create();
    print(root);
    puts("先序遍历结束");
    Queue *head = malloc(sizeof(Queue));
    head->next = NULL;
    ceng_print(root,head);
}