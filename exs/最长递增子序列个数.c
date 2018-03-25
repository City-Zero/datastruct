/*
头条一面题：
有一个无序数组，求出其最长递增子序列的个数
eg:
ip:
5
1 2 4 3 5
op:
2
tip:
1 2 3 5
1 2 4 5
*/
#include<stdio.h>
#include<string.h>
int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    int i,j;
    for(i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int a_t[2][n];
    memset(a_t,0,2*n*4);
    
    a_t[0][0] = 1;
    a_t[1][0] = 1;
    for(i = 1;i<n;i++){
        int max = 1;
        int times = 1;
        for(j = 0;j<i;j++){
            int m = 1;
            if(a[i] > a[j]){
                m = a_t[0][j] + 1;
            }
            else if(a[i] == a[j]){
                m  = a_t[0][j];
            }
            if(m > max){
                max = m;
                times = 1;
            }else if(m == max){
                times ++;
            }
        }
        a_t[0][i] = max;
        a_t[1][j] = times;
    }
    /*
    用一个二维数组，第一行为该位置最长可以组成的序列长度，第二行代表该长度的序列个数
    */
    for(i = 0;i<2;i++){
        for(j = 0;j<n;j++){
            printf("%d ",a_t[i][j]);
        }
        puts("");
    }
    return 0;
}