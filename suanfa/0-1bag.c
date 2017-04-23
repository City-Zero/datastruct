/*************************************************************************
	> File Name: 0-1bag.c
	> Author:李余通
	> Mail:1041984720@qq.com
	> Created Time: 2017年04月22日 星期六 15时37分10秒
 ************************************************************************/
#include<stdio.h>
int count = 4; //物品数量
int w[] = {1,3,4,5}; //物品重量数组
int v[] = {2,30,44,20}; //物品价值数组
int contain = 4; //背包容量

int f(int n,int c)
{
	int t = 0;
	int tmp1 = 0;
	int tmp2 = 0;
    //背包为0或物品数为0返回0
    if(n == -1){
		return 0;
    }
	if(c >= w[n]){
		tmp1 = f(n-1,c - w[n]) + v[n];
		tmp2 = f(n-1,c);
		if(tmp1 > tmp2){
			t = tmp1;
		}else{
			t = tmp2;
		}
		return t;
	}
	return f(n-1,c);
}

int main(void)
{
	int max = f(count - 1,contain);
	printf("max pic is %d\n",max);
}
