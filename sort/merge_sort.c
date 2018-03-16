/*************************************************************************
	> File Name: merge_sort.c
	> Author:lyt 
	> Mail:1041984720@qq.com 
	> Created Time: 2016年12月19日 星期一 17时52分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int merge(int *a,int *b,int left,int right,int middle)
{
    int i,p1,p2;

    //拷贝待排序序列
    for(i = left;i<=right;i++){
        b[i] = a[i];
    }

    p1 = left; //记录左半部的起始位置
    p2 = middle + 1; //记录右半部起始位置
    i = left; //从左开始归并
    while(p1<=middle && p2<=right){ //归并条件
        if(b[p1] <= b[p2]){
            a[i] = b[p1];
            p1++;
        }
        else {
            a[i] = b[p2];
            p2++;
        }
        i++;
    }

    //将未便利的添置后边
    while(p1<=middle){
        a[i] = b[p1];
        i++;
        p1++;
    }
    while(p2<=right){
        a[i] = b[p2];
        i++;
        p2++;
    }
}

int merge_sort(int *a,int *b,int left,int right)
{
    int middle;
    if(left < right){ //递归条件
        middle = (left + right)/2; //找到分割点
        merge_sort(a,b,left,middle); //递归排序左半部分
        merge_sort(a,b,middle+1,right);//递归排序又半部分
        merge(a,b,left,right,middle); //归并
    }
}


int main(void)
{
    int a[10] = {1,3,6,2,9,0,7,5,8,4};
    int *b = malloc(sizeof(a));
    merge_sort(a,b,0,9);
    int i = 0;
    for(i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
}
