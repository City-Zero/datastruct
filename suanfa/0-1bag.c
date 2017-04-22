/*************************************************************************
	> File Name: 0-1bag.c
	> Author:李余通
	> Mail:1041984720@qq.com
	> Created Time: 2017年04月22日 星期六 15时37分10秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
int count = 4; //物品数量
int w[] = {1,3,4,5}; //物品重量数组
int v[] = {2,30,44,20}; //物品价值数组
int contain = 5; //背包容量
int y[4];

int f(int n,int contain)
{
    //背包为0或物品数为0返回0
    if(n == 0 || contain == 0){
        return 0;
    }
    else{
        //从当前所剩物品的最后一个物品开始向前，逐个判断是否添加进背包
        int i;
        for(i = n - 1;i >= 0;i--){
            //如果当前要判断的物品重量大于背包当前所剩的容量，就不选择这个物品
            //这种情况下最优解为f(n-1,c)
            if(w[i] > contain){
                y[i] = 0;
                return f(n-1,contain);
            }
            else{
                //如果当前待判断的物品重量wi<c，那么选取f(n-1,c)和vi+f(n-1,c-wi)中的最大值
                int tmp1 = f(n-1,contain);//不选物品i下的最优解
                int tmp2 = f(n-1,contain-w[i]);//选择i下的最优解
                
                if(tmp1>tmp2){
                    y[i] = 0;
                    return tmp1;
                }
                else{
                    y[i] = 1;
                    return tmp2;
                }
            }
        }
    }
}

int main(void)
{
    memset(y,-1,sizeof(y));
	int max = f(count,contain);
    int i;
    for(i = 0;i<count;i++){
        if(y[i] == 1){
            printf("select %d:%d,%d\n",i+1,w[i],v[i]);
        }
    }
    printf("max pic is %d\n",max);

}
