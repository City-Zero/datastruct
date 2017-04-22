/*************************************************************************
	> File Name: merge_sort_ziran.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月23日 星期四 20时16分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int fenzu(int *a,int *b,int n)
{
    int i,j = 1;
    //合并的开始为-1是因为为了和后面统一为b[i]+1
    b[0] = -1;
    for(i = 1;i < n;i++){
        if(a[i] < a[i-1]){
            b[j] = i - 1;
            j++;
        }
    }
    b[j] = i-1;
    return j;
}
void merge(int *a,int start,int middle,int end)
{
    //合并a[start:middle]与a[middle+1:end]
    int *c = malloc(sizeof(int)*(end - start+1));
    int s = 0;
    int i,j;
    //保存到临时空间c
    for(i = start,j = middle+1;i<=middle &&j <= end;s++){
        if(a[i] < a[j]){
            c[s] = a[i];
            i++;
        }else{
            c[s] = a[j];
            j++;
        }
    }
    if(i>middle){
        for(j;j<=end;j++){
            c[s] = a[j];
            s++;
        }
    }
    if(j>end){
        for(i;i<=middle;i++){
            c[s] = a[i];
            s++;
        }
    }
    s = 0;
    for(i = start;i<=end;i++){
        a[i] = c[s];
        s++;
    }
}

void mergeSort(int *a,int *b,int n)
{
    int len = fenzu(a,b,n);
    int i = 0;
    while(len >= 2){
        for(i = 0;i<=len - 2;i+=2){
            merge(a,b[i]+1,b[i+1],b[i+2]);
        }
        len = fenzu(a,b,n);
    }
}

int main(void)
{
    int a[] = {9,8,7,6,5,4,3,2,1,0};
    int n = sizeof(a)/sizeof(int);
    int *b = malloc(sizeof(int)*n+1);
    memset(b,0,sizeof(b));
    mergeSort(a,b,n);
    int i;
    
    for(i = 0;i < n;i++){
        printf("%d ",a[i]);
    }
    
}
