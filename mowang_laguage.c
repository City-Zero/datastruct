/*************************************************************************
	> File Name: mowang_laguage.c
	> Author: 
	> Mail: 
	> Created Time: 2016年10月20日 星期四 19时52分42秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define XiaoZi 10 //小写字母个数
#define XiaoLong 10//每个小写字母对应的最多字符个数

#define DaZi 2 //大写字母个数
#define DaLong 10//每个大写字母对应的最多字符个数

char yuanshi[XiaoZi] = {'t','d','s','a','e','z','g','x','n','h'};
//人类语言小写字母
char hanzi[XiaoZi][XiaoLong] = {"天","地","上""一只","鹅","追","赶","下","蛋","恨"};
//翻译成中文对用的汉字
    
//魔王语言的大写字母
char dazi[DaZi] = {'A','B'};

//魔王语言对应的小写字母
char xiaozi[DaZi][DaLong] = {"sea","tAdA"};

typedef struct node{
    char *means; //实际汉字
    char word; //存储的字符
    struct node *next;
}Node;

void jieshi(char *a)
{
    int i;
}

Node* shuru(void)
{
    Node *head =(Node*)malloc(sizeof(Node));
    head->next = NULL;
    Node *temp = head;
    char a[20];
    scanf("%s",a);
    int i = 0;
    for(i;i < strlen(a);i++){
        Node *p = malloc(sizeof(Node));
        p->means = NULL;
        p->word = a[i];
        p->next = temp->next;
        temp->next = p;
        temp = p;
    }
    return head;
}
void Print(Node *head)
{
    Node *temp = head->next;
    while(temp){
        putchar(temp->word);
        temp = temp->next;
    }
}

int explan_kuohao_ok(Node *head)
{
    Node *temp = head->next;
    while(temp){
        if(temp->word == '(' || temp->word == ')'){
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

void explan_kuohao(Node *head)
{
    Node *temp = head->next;
    Node *lleft,*left,*right;
    while(temp){
        if(temp->next->word == '('){
            lleft = temp;
            left = temp->next;
        }
        if(temp->word == ')'){
            right = temp;
            break;
        }
        temp = temp->next;
    }

    lleft->next = right;//删除”（“到”）“之前的内容

    while(left->next != right){
        temp = left->next;
        while(temp->next->next != right){
            temp = temp->next;
        } //取到有括号的第前两个节点
        Node *p = malloc(sizeof(Node));
        p->word = left->next->word;//保存第一个字符
        p->next = temp->next;//保存最后一个字符
        temp->next = temp->next->next;//在去出的片段总取消最后一个字符
        lleft->next = p;
        lleft = p;//将第一个字符及最后一个字符解压至原链表
    }
    lleft->next = right->next;//将源节点连接起来
}
int explan_ok(Node *head)
{
    Node *temp = head->next;
    while(temp){
        if(temp->word >= 'A' && temp->word <= 'Z'){
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

void explan(Node *head)
{
    Node *xiuzheng;
    Node *temp = head;
    while(temp->next){
        if(temp->next->word >= 'A' && temp->next->word <= 'Z'){
            xiuzheng = temp->next;

        }
    }
}

int main(void)
{
    Node *SqStack = shuru();
    while(!explan_kuohao_ok(SqStack)){
        explan_kuohao(SqStack);
    }
    while(!explan_ok(SqStack)){
        explan(SqStack);
    }
    Print(SqStack);
}
