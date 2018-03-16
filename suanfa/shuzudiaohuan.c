/*************************************************************************
	> File Name: shuzudiaohuan.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月23日 星期四 18时25分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int func(int *a,int n,int k);

void pp(int *a,int n)
{
    int i = 0;
    for(i;i<n;i++)
        printf("%d ",a[i]);
    puts("");
}
int main(void)
{
    int n,k,i;
    //接收n,k,数组a
    scanf("%d%d",&n,&k);
    int *a = malloc(sizeof(int)*n);
    for(i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    func(a,n,k);
    return 0;
}

int func(int *a,int n,int k){
    int i = 0;
    int t;
    //反转a[0:k-1]
    for(i;i < (k)/2;i++){
        t = a[i];
        a[i] = a[k-i-1];
        a[k-i-1] = t;
    }
    //反转a[k,n-1]
    int j = 0;
    for(i = k;i<n - (n-k)/2;i++){
        t = a[i];
        a[i] = a[n-j-1];
        a[n-j-1] = t;
        j++;
    }

    //反转a[0:n-1]
    for(i = 0;i<(n-1)/2;i++){
        t = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = t;
    }
    pp(a,n);
}
