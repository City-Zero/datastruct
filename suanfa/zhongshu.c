/*************************************************************************
	> File Name: zhongshu.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月23日 星期四 16时51分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void sort(int *a,int n)
{

}
void func(int *a,int g);
int main(void)
{
    FILE *fda = NULL,*fdb = NULL;
    fda = fopen("./input.txt","r");
    int n;
    fscanf(fda,"%d",&n);
    int *a;
    a = malloc(sizeof(int) * n);
    int i;
    for(i = 0;i<n;i++){
        fscanf(fda,"%d",&a[i]);
    }
    func(a,n);
    return 0;
}

void func(int *a,int g){
    int m,n;
    int tm,tn;
    tm = m = a[0];
    n = tn = 1;
    int i = 1;
    for(i;i<g;i++){
        if(a[i] == tm){
            tn++;
        }else{
            if(tn > n){
                n = tn;
                m = tm;
            }
            tm = a[i];
            tn = 1;
        }
    }
    if(tn > n){
        n = tn;
        m = tm;
    }

    FILE *fd = NULL;
    fd = fopen("./output.txt","w");
    fprintf(fd,"%d\n%d\n",m,n);
    fclose(fd);
}
