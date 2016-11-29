/*************************************************************************
	> File Name: duoxiangshi.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月09日 星期五 10时43分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 200

void array_display(int a[])
{
    int i=0;
    for(i=0;i<Max;i++) {
        if(a[i] != 0){
            printf("%dx^%d+",a[i],i);
        }
    }
    printf("\b \n");
}

void array_Derivative(int a[],int b[])
{
    int i;
    int c[Max];
    int d[Max];
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(c));
    for(i=0;i<Max;i++){
        c[i-1] = a[i] * i;
        a[i] = 0;
        d[i-1] = b[i] * i;
        b[i] = 0;
    }
    printf("第一个多项式求导结果为:");
    array_display(c);
    printf("第二个多项式求导结果为:");
    array_display(d);
}


void array_minus(int a[],int b[])
{
    int i;
    int c[Max];
    memset(c,0,sizeof(c));
    for(i=0;i<Max;i++){
        c[i] = a[i] - b[i];
    }
    printf("两多项式相减的结果为:");
    array_display(c);
}

void array_plus(int a[],int b[])
{
    int i;
    int c[Max];
    memset(c,0,sizeof(c));
    for(i=0;i<Max;i++){
        c[i] = a[i] + b[i];
    }
    printf("第一个多项式为:");
    array_display(a);
    printf("第二个多项式为:");
    array_display(b);
    printf("两多项式相加的结果为:");
    array_display(c);
}

void array(void)
{
    printf("请输入第一个多项式的项数:");
    int n1,n2;
    scanf("%d",&n1);
    printf("请输入第一个多项式的系数和指数，用逗号隔开系数和指数:");
    int a[Max];
    int b[Max];
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
    int i;
    int d,x;
    for(i=0;i<n1;i++) {
        scanf("%d,%d",&d,&x);
        a[x] = d;
    }
    printf("请输入第二个多项式的项数:");
    scanf("%d",&n1);
    printf("请输入第二个多项式的系数和指数，用逗号隔开系数和指数:");
    for(i=0;i<n1;i++) {
        scanf("%d,%d",&d,&x);
        b[x] = d;
    }
    array_plus(a,b);
    array_minus(a,b);
    array_Derivative(a,b);
}

int main(void)
{
    //link_list();
    array();
    return 0;
}
