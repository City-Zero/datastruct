/*************************************************************************
	> File Name: huiwen.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月20日 星期二 13时26分29秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int huiwen(char a[])
{
    int n = strlen(a)/2;
    char s[n];
    int i;
    for(i=0;i<n;i++){
        s[i] = a[i];
    }
    if(strlen(a) % 2 == 1)
        i++;
    for(i;i<strlen(a);i++){
        if(a[i] != s[n-1])
            return 0;
        n--;
    }
    return 1;
}

int main(void)
{
    char a[100];
    scanf("%s",a);
    printf("%d\n",huiwen(a));
    return 0;
}
