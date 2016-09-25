/*************************************************************************
	> File Name: duoxiangshi.c
	> Author: 
	> Mail: 
	> Created Time: Fri Sep 23 10:58:54 2016
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define Max 10000
void display(int a[])
{
    int flag = 0;
    int i = 0;
    for(i = 0;i < Max;i++){
        if(a[i] != 0){
            if(i == 0)
                printf("%d",a[i]);
            else if(i == 1){
                if(flag && a[i] > 0){
                    printf("+");
                    if(a[i] == 1)
                        printf("X");
                    else 
                        printf("%dX",a[i]);
                }
                else{
                    if(a[i] == -1)
                        printf("-X");
                    else 
                        printf("%dX",a[i]);
                }
            }
            else{
                if(flag){
                    if(a[i] > 0)
                        printf("+");
                    if(a[i] == 1)
                        printf("X^%d",i);
                    else 
                        printf("%dX^%d",a[i],i);
                }
                else{
                    if(a[i] == -1)
                        printf("-X^%d",i);
                    else 
                        printf("%dX^%d",a[i],i);
                } 
            }
            flag++;
        }
    }
}

void add(int a[],int b[])
{
    int i;
    i = 0;
    int c[Max];
    memset(c,0,sizeof(c));
    for(i = 0;i < Max;i++){
        c[i] = a[i] + b[i];
    }
    display(c);
}

int main(void)
{
    int a[Max];
    int b[Max];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(a));
    int n;
    scanf("%d",&n);
    int s,l;
    int i = 0;
    for(i;i < n;i++){
        scanf("(%d,%d)",&s,&l);
        a[l] = s;
    }
    scanf("%d",&n);
    for(i=0;i < n;i++){
        scanf("(%d,%d)",&s,&l);
        b[l] = s;
    }
    add(a,b);
    return 0;
}

