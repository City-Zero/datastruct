/*************************************************************************
	> File Name: quick_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2016年12月19日 星期一 15时54分04秒
 ************************************************************************/

#include<stdio.h>

int qk_pass(int* a,int low,int high)
{
    int flag = a[low];//记录标杆
    while(low<high){
        while(a[high] > flag && high > low) high--;
        a[low] = a[high];//在右边找到小于标杆的
        while(a[low] < flag && low < high) low++;
        a[high] = a[low];//在左找到大于标杆的
    }
    a[low] = flag;//标杆移位
    return low;

}

int qk_sort(int* a,int low,int high)
{
    if(low < high){ //停止递归的条件
        int pass = qk_pass(a,low,high);
        qk_sort(a,low,pass - 1); //排序左边
        qk_sort(a,pass + 1,high); //排序右边
    }
    return 0;
}

int main(void)
{
    int a[10] = {3,6,4,7,9,1,2,8,0,5};
    qk_sort(a,0,9);
    int i = 0;
    for(i = 0;i<10;i++){
        printf("%d ",a[i]);
    }
}
