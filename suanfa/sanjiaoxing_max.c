/*************************************************************************
	> File Name: sanjiaoxing_max.c
	> Author:李余通
	> Mail:1041984720@qq.com
	> Created Time: 2017年04月14日 星期五 15时35分27秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(void)
{
    FILE *fp = fopen("sanjiaoxing.input","r");
    int n;
    fscanf(fp,"%d",&n);
    int arr[n][n];
    int arr_val[n][n];
    memset(arr,0,sizeof(arr));
    memset(arr_val,0,sizeof(arr_val));
    int i,j;
    for(i = 0;i < n;i++){
        for(j = 0;j <= i;j++){
            fscanf(fp,"%d",&arr[i][j]);
        }
    }

    arr_val[0][0] = arr[0][0];
    for(i = n - 2;i >= 0;i--){
        for(j = 0;j <= i;j++){
            if(arr[i+1][j] > arr[i+1][j+1]){
                arr[i][j] += arr[i+1][j];
            }else{
                arr[i][j] += arr[i+1][j+1];
            }
        }
    }
    printf("%d",arr[0][0]);
}
