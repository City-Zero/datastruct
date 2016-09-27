/*************************************************************************
	> File Name: tongpai.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月27日 星期二 20时08分52秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define N 3
int main(void)
{
    int a[N];
    int b[101];
    memset(b,0,sizeof(b));
    int i;
    int j=0;
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    for(i=0;i<N;i++)
        b[a[i]]++;
    for(i=0;i<101;i++)
    {
        while(b[i] != 0)
        {
            a[j]=i;
            j++;
            b[i]--;
        }
    }
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
}

